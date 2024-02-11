#include "utils.h"
#include "tree.h"

utils uc;
tree Tree;

void bubbleSort()
{
    //bubblesort algo
    for (size_t i = 0; i < uc.frequencyTable.size() - 1; i++)
    {
        bool change = false;
        if(uc.frequencyTable[i].frequency > uc.frequencyTable[i + 1].frequency)
        {
            change = true;
            uc.temp = uc.frequencyTable[i + 1];
            uc.frequencyTable[i + 1] = uc.frequencyTable[i];
            uc.frequencyTable[i] = uc.temp;
        }
        if(change)
            bubbleSort();
    }
}

void createBinaryTree()
{
    while(uc.frequencyTable.size() > 1){
        bool extraNodeAdded = false;
        int vecOffset;
        
        int sumFreq = uc.frequencyTable[0].frequency + uc.frequencyTable[1].frequency;

        Tree.createNode(uc.frequencyTable[0].frequency + uc.frequencyTable[1].frequency, 0);

        if(uc.frequencyTable[0].existsInTree)
        {
            Tree.treeStorage[Tree.treeStorage.size() - 1].ptr_left_node = uc.frequencyTable[0].ptr_tree_address;
        }
        else{
            extraNodeAdded = true;
            Tree.addNode(uc.frequencyTable[0].letter, uc.frequencyTable[0].frequency, Tree.treeStorage[Tree.treeStorage.size() - 1], 0);
        }
        if(extraNodeAdded) { vecOffset = 2; } else { vecOffset = 1; }
        ///
        if(uc.frequencyTable[1].existsInTree)
        {
            Tree.treeStorage[Tree.treeStorage.size() - vecOffset].ptr_right_node = uc.frequencyTable[1].ptr_tree_address;
        }
        else{
            Tree.addNode(uc.frequencyTable[1].letter, uc.frequencyTable[1].frequency, Tree.treeStorage[Tree.treeStorage.size() - vecOffset], 1);
            vecOffset++;
        }
        uc.frequencyTable.erase(uc.frequencyTable.begin());
        uc.frequencyTable[0].frequency = sumFreq;
        uc.frequencyTable[0].ptr_tree_address = &Tree.treeStorage[Tree.treeStorage.size() - vecOffset];
        uc.frequencyTable[0].existsInTree = true;

        bubbleSort();

    }
} 


int main(int argc, char *argv[])
{
    std::string input; 
    std::getline(std::cin, input);
    uc.calcFrequency(input);
    bubbleSort();
    std::cout << "Sorted version" << '\n';
    for (auto i: uc.frequencyTable)
    {
        std::cout << i.letter << ',';
        std::cout << i.frequency << '\n' << "\n";
    }
    createBinaryTree();
    for(size_t i = 0; i < Tree.treeStorage.size(); i++)
    {
        std::cout << Tree.treeStorage[i].data << " ,";
        std::cout << Tree.treeStorage[i].frequency << "\n";
    }
    return 0;
}

