#include "Text.hpp"
#include "utfConvert.hpp"

#include <vector>
#include <iostream>
#include <set>

void Text::initCharCount(std::ifstream& inFile, Assets& assets){
    const std::u32string& allowed = assets.getCharTypes().at("all");
    const std::set<char32_t> allowedSet(allowed.begin(), allowed.end());

    std::string line;

    while(getline(inFile, line)){
        std::u32string converted = conv.from_bytes(line);
        for(char32_t c : converted){
            c = std::towlower(c);
            if (!allowedSet.contains(c)){
                continue;
            }
            this->charCount[c]++;
        }
    }
}
