#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include <iterator>
#include <stack>

#include "node.h"

class TreeIterator : public std::iterator<std::forward_iterator_tag, int>
{
    std::stack <NodePtr> s;
	void clear();
	void downLeft();
public:
    TreeIterator() { }
    TreeIterator(NodePtr startNode);
    int operator*();
    TreeIterator& operator++();
    TreeIterator operator++(int);
    bool operator==(const TreeIterator& rhs);
    bool operator!=(const TreeIterator& rhs) { return !operator ==(rhs);}
};

#endif // TREEITERATOR_H
