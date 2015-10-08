#include <stdexcept>

#include "treeiterator.h"

TreeIterator::TreeIterator(NodePtr startNode)
{
    s.push(startNode);
    downLeft();
}

bool TreeIterator::operator==(const TreeIterator& rhs) 
{
    if (rhs.s.empty() || s.empty())
        return rhs.s.empty() && s.empty();
    else
        return s.top() == rhs.s.top();
}


int TreeIterator::operator*()
{
    if (s.empty()) {
        throw std::logic_error("разыменовывание невалидного итератора");
    }
    return s.top()->value();
}

TreeIterator& TreeIterator::operator++()
{ 
    if (s.empty())
        return *this;

    if (s.top()->color() == White) {
        if (s.top()->isLeaf()) {
            s.pop();
            clear();
        }
        else {
            s.top()->setColor(Black);
            s.push(s.top()->right());
            downLeft();
        }
    }
    else if (s.top()->color() == Grey) {
        if (s.top()->right()) {
            s.top()->setColor(Black);
            s.push(s.top()->right());
            downLeft();
        }
        else {
            s.pop();
            clear();
        }
    }
    return *this;

}

TreeIterator TreeIterator::operator++(int)
{
    TreeIterator tmp(*this);
    operator ++();
    return tmp;
}

void TreeIterator::clear() 
{
    while (!s.empty() && s.top()->color() == Black) {
        s.pop();
    }
}

void TreeIterator::downLeft() 
{
    while (s.top()->color() == White && s.top()->left()) {
        s.top()->setColor(Grey);
        s.push(s.top()->left());
    }
}
