#pragma once

#include <stack>

#include "command.hpp"
#include "figure.hpp"
#include "document.hpp"

struct editor {
private:
    std::shared_ptr<document> doc_;
    std::stack<std::shared_ptr<Command>> history_;
public:
    ~editor() = default;

    void PrintDocument();
    void CreateDocument(std::string& newName);
    bool DocumentExist();
    editor() : doc_(nullptr), history_()
    {}
    
    void InsertInDocument(std::shared_ptr<Figure>& newFigure);
    void DeleteInDocument(size_t index);
    void SaveDocument();
    void LoadDocument(std::string& name);
    void Undo();
};
