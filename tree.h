#pragma once

#include <vector>

class tree{
public:
    struct Node
    {   
        char data;
        int frequency;
        Node* ptr_left_node;
        Node* ptr_right_node;
    };
    std::vector<Node> treeStorage;
    void addNode(char data, int freq, Node parent_node, int left_or_right);
    void createNode(int freq, int address);
};