#pragma once

#include <iostream>
#include <string>
#include <vector>
#include"tree.h"

class utils{
public:
    struct letterFrequency {
        char letter;
        int frequency;
        bool existsInTree = false;
        tree::Node* ptr_tree_address;
    };
    std::vector<letterFrequency> frequencyTable;
    void calcFrequency(std::string str);
    letterFrequency temp;
};