#ifndef NODE_H
#define NODE_H

#include <memory>

enum Color {
    White,
    Grey,
    Black
};

class Node
{
    Color color_;
    std::shared_ptr<Node> left_;
    std::shared_ptr<Node> right_;
    int value_;
public:
    Node(int key, std::shared_ptr<Node> leftChildren = nullptr, std::shared_ptr<Node> rightChildren = nullptr)
        : color_(White) , left_(leftChildren), right_(rightChildren), value_(key) { }

    int value() { return value_;}
    std::shared_ptr<Node> left() { return left_;}
    std::shared_ptr<Node> right() { return right_;}
    Color color() { return color_;}
    void setColor(Color c) { color_ = c;}
    bool isLeaf() { return left_ == nullptr && right_ == nullptr; }
};

using NodePtr = std::shared_ptr<Node>;

#endif // NODE_H
