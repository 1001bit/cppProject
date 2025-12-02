#pragma once

#include <fstream>
#include <map>
#include <string>

extern const std::map<std::string, std::u32string> charTypes;

struct AltStats {
    double conBefore;
    double conAfter;
    double vowBefore;
    double vowAfter;
};

class Text
{
private:
    // 1
    std::map<std::string, std::map<char32_t, double>> charStats;
    void initCharStats(std::ifstream& inFile);

    // 5
    std::map<char32_t, AltStats> conAltStats;
    std::map<char32_t, AltStats> vowAltStats;
    void initAltStats(std::ifstream& inFile); 

public:
    Text(std::string txtPath);

    const std::map<std::string, std::map<char32_t, double>>& getCharStats() const { return this->charStats; }
    const std::map<char32_t, AltStats>& getConAltStats() const {return this->conAltStats;}
    const std::map<char32_t, AltStats>& getVowAltStats() const {return this->vowAltStats;}

};
