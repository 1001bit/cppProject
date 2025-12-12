#include "Text.hpp"
#include "utfConvert.hpp"
#include "maskWord.hpp"

#include <algorithm>
#include <iostream>
#include <set>

void Text::countWords(std::ifstream& inFile, Assets& assets){
    const std::map<std::string, std::u32string>& charTypes = assets.getCharTypes();
    const std::set<char32_t> letters(charTypes.at("letters").begin(), charTypes.at("letters").end());

    std::string word;
    while(inFile >> word){
        std::u32string masked = maskWord(word, charTypes.at("letters") + U'-');
        const bool hasLetters = std::any_of(masked.begin(), masked.end(), [&](char32_t c){
            return letters.count(c);
        });

        if (!hasLetters){
            continue;
        }

        this->wordsCount[masked]++;
    }
}
