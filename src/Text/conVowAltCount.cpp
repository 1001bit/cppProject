#include "Text.hpp"

#include <iostream>
#include <set>
#include <vector>

void Text::initConVowAltCount(Assets& assets){
    const std::map<std::string, std::u32string>& charTypes = assets.getCharTypes();

    const std::set<char32_t> vows(charTypes.at("vows").begin(), charTypes.at("vows").end());
    const std::set<char32_t> cons(charTypes.at("cons").begin(), charTypes.at("cons").end());

    for(char32_t c : (charTypes.at("vows") + charTypes.at("cons"))){
        conVowAltCount[c] = ConVowAltCount{0, 0, 0, 0};
    }

    for (auto& it : this->wordsCount){
        const std::u32string& word = it.first;
        int wordCount = it.second;

        for (size_t i = 0; i < word.size(); i++){
            char32_t c = word[i];
            
            if (!conVowAltCount.count(c)){
                continue;
            }
            ConVowAltCount& cnt = conVowAltCount[c];

            cnt.vowBefore += wordCount * (i > 0 && vows.count(word[i-1]));
            cnt.conBefore += wordCount * (i > 0 && cons.count(word[i-1]));
            cnt.vowAfter += wordCount * (i < word.size()-1 && vows.count(word[i+1]));
            cnt.conAfter += wordCount * (i < word.size()-1 && cons.count(word[i+1]));
        }
    }
}