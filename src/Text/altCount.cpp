#include "Text.hpp"
#include "utfConvert.hpp"

#include <iostream>
#include <set>
#include <vector>

void Text::initAltCount(std::ifstream& inFile){
    std::string line;

    for(char32_t c : (charTypes.at("vows") + charTypes.at("cons"))){
        altCount[c] = AltCount{0, 0, 0, 0};
    }

    const std::set<char32_t> vows(charTypes.at("vows").begin(), charTypes.at("vows").end());
    const std::set<char32_t> cons(charTypes.at("cons").begin(), charTypes.at("cons").end());

    while(getline(inFile, line)){
        std::u32string converted = conv.from_bytes(line);
        for (size_t i = 0; i < converted.size(); i++){
            char32_t c = converted[i];
            
            if (!altCount.contains(c)){
                continue;
            }
            AltCount& cnt = altCount[c];

            if (i > 0 && vows.count(converted[i-1])){
                cnt.vowBefore += 1;
            }
            if (i > 0 && cons.count(converted[i-1])){
                cnt.conBefore += 1;
            }
            if (i < converted.size()-1 && vows.count(converted[i+1])){
                cnt.vowAfter += 1;
            }
            if (i < converted.size()-1 && cons.count(converted[i+1])){
                cnt.conAfter += 1;
            }
        }
    }
}