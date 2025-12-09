#include "Text.hpp"
#include "utfConvert.hpp"
#include "charTypes.hpp"

#include <iostream>
#include <set>

std::u32string maskWord(std::string word){
    std::u32string res = U"";
    std::set<char32_t> letters(charTypes.at("letters").begin(), charTypes.at("letters").end());

    for(char32_t c : conv.from_bytes(word)){
        c = towlower(c);
        if (letters.contains(c) || c == U'-'){
            res += c;
        }
    }

    return res;
}

void Text::countWords(std::ifstream& inFile){
    std::string word;
    while(inFile >> word){
        std::u32string masked = maskWord(word);
        if (masked.size()){
            this->wordsCount[masked]++;
        }
    }
}