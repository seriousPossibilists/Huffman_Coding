#include "utils.h"

//utils Utilities;





void utils::calcFrequency(std::string str)
{
    //looping over each string character;
    for (size_t i = 0; i < str.length(); i++)
    {
        bool changed = false;
        for (size_t j = 0; j < frequencyTable.size(); j++)
        {
            //checking if frequency table already contains current character;
            if(frequencyTable[j].letter == str[i])
            {
                changed = true;
                frequencyTable[j].frequency++;
            }
        }
        if(!changed)
        {
            //current char not in table; adding new struct to represent the char;
            utils::letterFrequency newLetter;
            newLetter.frequency = 1; newLetter.letter = str[i];
            frequencyTable.push_back(newLetter);
        }

    }
    
    for (auto i: frequencyTable)
    {
        std::cout << i.letter << ',';
        std::cout << i.frequency << '\n';
    }
    // Sorting to get lower frequency first;(using bubble sort)

}