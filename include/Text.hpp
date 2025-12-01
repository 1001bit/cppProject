#pragma once

#include <fstream>
#include <unordered_map>
#include <string>

class Text
{
private:
    std::unordered_map<char32_t, int> charCount;
    // TODO:
    // unordered_map<int, int> wordLenCount;
    // unordered_map<int, int> sentenceLenCount;

    void countChars(std::ifstream& inFile);

public:
    Text(std::string txtPath);

    std::unordered_map<char32_t, double> getCharPercentage();
    // TODO:
    // unordered_map<int, int> getWordLenPercentage();
    // unordered_map<int, int> getSentenceLenPercentage();
};
