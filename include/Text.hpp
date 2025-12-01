#pragma once

#include <fstream>
#include <unordered_map>
#include <string>

class Text
{
private:
    // 1
    std::unordered_map<std::string, std::unordered_map<char32_t, double>> charStats;
    void initCharStats(std::ifstream& inFile);

public:
    Text(std::string txtPath);

    const std::unordered_map<std::string, std::unordered_map<char32_t, double>>& getCharStats() const { return this->charStats; }
};
