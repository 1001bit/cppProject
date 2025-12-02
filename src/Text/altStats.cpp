#include "Text.hpp"
#include "utfConvert.hpp"

#include <iostream>
#include <set>

void Text::initAltStats(std::ifstream& inFile){
    std::string line;

    std::map<char32_t, AltStats> vowAltStats;
    std::map<char32_t, AltStats> conAltStats;

    for(char32_t c : charTypes.at("vows")){
        vowAltStats[c] = {
            0, 0, 0, 0
        };
    }

    for(char32_t c : charTypes.at("cons")){
        conAltStats[c] = {
            0, 0, 0, 0
        };
    }

    while(getline(inFile, line)){
        std::u32string converted = conv.from_bytes(line);
        for (size_t i = 0; i < converted.size(); i++){
            char32_t c = converted[i];
            
            AltStats* stats = nullptr;
            if (vowAltStats.count(c)){
                stats = &vowAltStats[c];
            } else if (conAltStats.count(c)){
                stats = &conAltStats[c];
            } else {
                continue;
            }

            if (i > 0 && vowAltStats.count(converted[i-1])){
                stats->vowBefore += 1;
            }
            if (i > 0 && conAltStats.count(converted[i-1])){
                stats->conBefore += 1;
            }
            if (i < converted.size()-1 && vowAltStats.count(converted[i+1])){
                stats->vowAfter += 1;
            }
            if (i < converted.size()-1 && conAltStats.count(converted[i+1])){
                stats->conAfter += 1;
            }
        }
    }

    for (auto& it : vowAltStats){
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

    this->vowAltStats = vowAltStats;
    this->conAltStats = conAltStats;
}