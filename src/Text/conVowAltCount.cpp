#include "Text.hpp"
#include "charTypes.hpp"
#include "utfConvert.hpp"

#include <iostream>
#include <set>
#include <vector>

void Text::initConVowAltCount(std::ifstream& inFile){
    for(char32_t c : (charTypes.at("vows") + charTypes.at("cons"))){
        conVowAltCount[c] = ConVowAltCount{0, 0, 0, 0};
    }

    const std::set<char32_t> vows(charTypes.at("vows").begin(), charTypes.at("vows").end());
    const std::set<char32_t> cons(charTypes.at("cons").begin(), charTypes.at("cons").end());

    std::string word;
    while(inFile >> word){
        std::u32string wordConv = conv.from_bytes(word);
        for (size_t i = 0; i < wordConv.size(); i++){
            char32_t c = wordConv[i];
            
            if (!conVowAltCount.contains(c)){
                continue;
            }
            ConVowAltCount& cnt = conVowAltCount[c];

            if (i > 0 && vows.count(wordConv[i-1])){
                cnt.vowBefore += 1;
            }
            if (i > 0 && cons.count(wordConv[i-1])){
                cnt.conBefore += 1;
            }
            if (i < wordConv.size()-1 && vows.count(wordConv[i+1])){
                cnt.vowAfter += 1;
            }
            if (i < wordConv.size()-1 && cons.count(wordConv[i+1])){
                cnt.conAfter += 1;
            }
        }
    }
}