#include "Text.hpp"
#include "utfConvert.hpp"
#include "maskWord.hpp"

#include <algorithm>
#include <set>

void Text::initWordLenCount(){
    for (auto& it : this->wordsCount){
        this->wordLenCount[it.first.size()] += it.second;
    }
}

void Text::initSentenceLenCount(std::ifstream& inFile, Assets& assets){
    std::set<char> punct{'!', '.', '?'};
    const std::map<std::string, std::u32string>& charTypes = assets.getCharTypes();
    const std::set<char32_t> letters(charTypes.at("letters").begin(), charTypes.at("letters").end());
    
    int sentenceLen = 0;
    std::string word;
    while(inFile >> word){
        std::u32string masked = maskWord(word, charTypes.at("letters") + U'-');
        const bool hasLetters = std::any_of(masked.begin(), masked.end(), [&](char32_t c){
            return letters.contains(c);
        });

        if (hasLetters){
            sentenceLen++;
        }

        if (!word.empty() && punct.contains(word[word.size()-1])) {
            if (sentenceLen > 0){
                this->sentenceLenCount[sentenceLen]++;
            }
            sentenceLen = 0;
        }
    }
}
