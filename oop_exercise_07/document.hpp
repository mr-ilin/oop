#pragma once

#include <fstream>
#include <cstdint>
#include <memory>
#include <string>
#include <algorithm>
#include <vector>

#include "figure_factory.hpp"
#include "figure.hpp"

struct document {
public:
    document(std::string& newName): name_(newName), factory_(), buffer_(0) {};
    
    void Print() const ;
    void Insert(std::shared_ptr<Figure>& ptr);
    void Rename(const std::string& newName);
    void Save (const std::string& filename) const;
    void Load(const std::string& filename);
    void Erase(size_t index);
    
    std::shared_ptr<Figure> GetFigure(size_t index);
    std::string GetName();
    size_t Size();

private:
    friend class InsertCommand;
    friend class DeleteCommand;
    
    factory factory_;
    std::string name_;
    std::vector<std::shared_ptr<Figure>> buffer_;

    void RemoveLast();
    void InsertIndex(std::shared_ptr<Figure>& newFigure, size_t index);
};
