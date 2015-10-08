#include <algorithm>
#include <iostream>
#include <vector>

#include "tree.h"

int main()
{
    auto n1 = std::make_shared<Node>(1);
    auto n5 = std::make_shared<Node>(5);
    auto n2 = std::make_shared<Node>(2, n1, nullptr);
    auto n4 = std::make_shared<Node>(4, nullptr, n5);
    auto n3 = std::make_shared<Node>(3, n2, n4);

    auto m1 = std::make_shared<Node>(1);
    auto m3 = std::make_shared<Node>(3);
    auto m6 = std::make_shared<Node>(6);
    auto m2 = std::make_shared<Node>(2, m1, m3);
    auto m5 = std::make_shared<Node>(5, nullptr, m6);
    auto m4 = std::make_shared<Node>(4, m2, m5);

    Tree firstTree(n3);
    Tree secondTree(m4);

    std::set_intersection(firstTree.begin(), firstTree.end(),
                          secondTree.begin(), secondTree.end(),
                          std::ostream_iterator<int> (std::cout, " "));

    std::cin.get();

    return 0;
}
