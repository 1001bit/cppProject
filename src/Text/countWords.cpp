#include "Text.hpp"
#include "utfConvert.hpp"
#include "maskWord.hpp"

#include <iostream>
#include <set>

void Text::countWords(std::ifstream& inFile, Assets& assets){
    std::string word;
    while(inFile >> word){
        std::u32string masked = maskWord(word, assets.getCharTypes().at("letters") + U'-');
        if (masked.size()){
            this->wordsCount[masked]++;
        }
    }
}