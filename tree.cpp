#include "tree.h"
//left node should represent lowest frequency
void tree::addNode(char data, int freq, Node parent_node, int left_or_right)
{
    Node new_node;
    new_node.data = data;
    new_node.frequency = freq;
    if(left_or_right == 0)
        parent_node.ptr_left_node = &new_node;
    else{
        parent_node.ptr_right_node = &new_node;
    }
    tree::treeStorage.push_back(new_node);
};

void tree::createNode(int freq, int address)
{
    Node new_node;
    new_node.frequency = freq;
    tree::treeStorage.push_back(new_node);
}



