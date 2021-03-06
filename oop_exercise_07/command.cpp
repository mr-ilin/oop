#include "command.hpp"

void InsertCommand::UnExecute() {
    doc_->RemoveLast();
}

InsertCommand::InsertCommand(std::shared_ptr<document> &doc) {
    doc_ = doc;
}

DeleteCommand::DeleteCommand(std::shared_ptr<Figure> &newFigure, size_t newIndex, std::shared_ptr<document> &doc) {
    doc_ = doc;
    figure_ = newFigure;
    index_ = newIndex;
}

void DeleteCommand::UnExecute() {
    doc_->InsertIndex(figure_,index_);
}
