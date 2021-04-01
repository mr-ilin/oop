#include <iostream>
#include <fstream>
#include <list>
#include <future>
#include <condition_variable>

#include "figure.hpp"

class Document {
public:
    Document(int size = 3)
    : _critical_size(size) {
        _fut_func = std::async([&]() { ExportToFile(); });
    }

    ~Document() {
        _insertion_stop = true;
        _export.notify_all();
        _fut_func.get();
    }

    void Export() {
        static int i = 0;
        ++i;
        std::ofstream out("chunk" + std::to_string(i) + ".txt");
        for (const auto& ptr : _buffer) {
            ptr->WriteToFile(out);
        }
        out << "\n";
    }

    void Add(std::shared_ptr<Figure> figure_ptr) {
        std::unique_lock<std::mutex> lock(_m);
        _insertion.wait(lock, [&] { return _buffer.size() < _critical_size; });

        _buffer.push_back(std::move(figure_ptr));

        _export.notify_all();
    }

    void Print() const {
        static int i = 0;
        ++i;
        std::cout << i << ") chunk" << std::endl;
        for (const auto& ptr : _buffer) {
            ptr->Print(std::cout);
        }
        std::cout << std::endl;
    }

private:
    const size_t _critical_size;
    
    std::list<std::shared_ptr<Figure>> _buffer;

    std::mutex _m;
    std::condition_variable _insertion;
    std::condition_variable _export;
    std::future<void> _fut_func;
    bool _insertion_stop = false;

    void ExportToFile() {
        while (!_insertion_stop) {
            std::unique_lock<std::mutex> lock(_m);
            _export.wait(lock, [&] { return (_buffer.size() >= _critical_size) ||  _insertion_stop; });
            
            if (!_buffer.empty()) {
                Print();
                Export();
                _buffer.clear();
            }
        
            _insertion.notify_all();
        }
    }
};
