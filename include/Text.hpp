#pragma once

#include <fstream>
#include <map>
#include <string>
#include <vector>

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
    std::map<std::u32string, int> wordsCount;
    void countWords(std::ifstream& inFile);

    // 1
    std::map<char32_t, double> charStats;
    void initCharStats(std::ifstream& inFile);

    // 5
    std::map<char32_t, AltStats> altStats;
    void initAltStats(std::ifstream& inFile);

public:
    Text(std::string txtPath);

    // 1
    const std::map<char32_t, double>& getCharStats() const { return this->charStats; }
    // 5
    const std::map<char32_t, AltStats>& getAltStats() const { return this->altStats; }
    // 9
    const std::vector<std::pair<std::u32string, int>> getTopWords() const;
};
