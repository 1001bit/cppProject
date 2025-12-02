#include "Text.hpp"
#include "utfConvert.hpp"

#include <vector>
#include <iostream>

std::map<char32_t, int> getCharCount(std::ifstream& inFile){
    std::map<char32_t, int> charCount;
    std::string line;

    while(getline(inFile, line)){
        std::u32string converted = conv.from_bytes(line);
        for(char32_t c : converted){
            charCount[std::towlower(c)]++;
        }
    }

    return charCount;
}

void Text::initCharStats(std::ifstream& inFile){
    std::map<char32_t, int> charCount = getCharCount(inFile);
    std::map<char32_t, double>& charStats = this->charStats;

    const std::u32string& chars = charTypes.at("all");
    double totalCnt = 0;

    for(char32_t c : chars){
        totalCnt += charCount[c];
        charStats[c] = 0;
    }

    if(totalCnt == 0){
        return;
    }

    for(char32_t c : chars){
        charStats[c] = charCount[c]/totalCnt;
    }
}
