#include "Text.hpp"
#include "utfConvert.hpp"

#include <iostream>
#include <set>
#include <vector>

void Text::initAltStats(std::ifstream& inFile){
    std::string line;

    std::map<char32_t, AltStats>& altStats = this->altStats;
    for(char32_t c : (charTypes.at("vows") + charTypes.at("cons"))){
        altStats[c] = AltStats{0, 0, 0, 0};
    }

    const std::set<char32_t> vows(charTypes.at("vows").begin(), charTypes.at("vows").end());
    const std::set<char32_t> cons(charTypes.at("cons").begin(), charTypes.at("cons").end());

    while(getline(inFile, line)){
        std::u32string converted = conv.from_bytes(line);
        for (size_t i = 0; i < converted.size(); i++){
            char32_t c = converted[i];
            
            if (!altStats.contains(c)){
                continue;
            }
            AltStats& stats = altStats[c];

            if (i > 0 && vows.count(converted[i-1])){
                stats.vowBefore += 1;
            }
            if (i > 0 && cons.count(converted[i-1])){
                stats.conBefore += 1;
            }
            if (i < converted.size()-1 && vows.count(converted[i+1])){
                stats.vowAfter += 1;
            }
            if (i < converted.size()-1 && cons.count(converted[i+1])){
                stats.conAfter += 1;
            }
        }
    }

    for (auto& it : altStats){
        AltStats& s = it.second;
        double totalBefore = s.conBefore + s.vowBefore;
        double totalAfter = s.conAfter + s.vowAfter;

        if (totalBefore != 0){
            s.conBefore = s.conBefore/totalBefore;
            s.vowBefore = 1-s.conBefore;
        }
        if (totalAfter != 0){
            s.conAfter = s.conAfter/totalAfter;
            s.vowAfter = 1-s.conAfter;
        }
    }
}