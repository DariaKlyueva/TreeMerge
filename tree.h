#ifndef TREE_H
#define TREE_H

#include "node.h"
#include "treeiterator.h"

class Tree
{
    NodePtr root;
    TreeIterator iterator;
public:
    Tree(NodePtr root)
        : root(root), iterator(root) { }
    TreeIterator begin() {return iterator;}
    TreeIterator end() {return TreeIterator();}
};

#endif // TREE_H
