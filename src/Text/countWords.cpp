#include "../../include/Text.hpp"
#include "../../include/utfConvert.hpp"
#include "../../include/charTypes.hpp"
#include "../../include/maskWord.hpp"

#include <iostream>
#include <set>

void Text::countWords(std::ifstream& inFile){
    std::string word;
    while(inFile >> word){
        std::u32string masked = maskWord(word);
        if (masked.size()){
            this->wordsCount[masked]++;
        }
    }
}
