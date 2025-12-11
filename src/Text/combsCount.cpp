#include "Text.hpp"
#include "utfConvert.hpp"

#include <set>
#include <iostream>

void Text::initCombsCount(Assets& assets){
    for (auto& it : this->wordsCount){
        const std::u32string& word = it.first;
        int wordCount = it.second;

        for (auto& comb : assets.getCombinations()){
            for (size_t pos = word.find(comb); pos != std::u32string::npos; pos = word.find(comb, pos+1)){
                this->combsCount[comb] += wordCount;
            }
        }
    }
}