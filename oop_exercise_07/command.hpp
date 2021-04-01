#pragma once 

#include "document.hpp"

struct Command {
    virtual ~Command() = default;
    virtual void UnExecute() = 0;

protected:
    std::shared_ptr<document> doc_;
};

struct InsertCommand : public Command {
public:
    void UnExecute() override;
    InsertCommand(std::shared_ptr<document>& doc);
};

struct DeleteCommand : public Command {
public:
    DeleteCommand(std::shared_ptr<Figure>& newFigure, size_t newIndex, std::shared_ptr<document>& doc);
    void UnExecute() override;

private:
    std::shared_ptr<Figure> figure_;
    size_t index_;
};
