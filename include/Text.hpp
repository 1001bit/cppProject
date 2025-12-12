#pragma once

#include "Assets.hpp"

#include <fstream>
#include <map>
#include <string>
#include <vector>

struct ConVowAltCount {
    int conBefore;
    int conAfter;
    int vowBefore;
    int vowAfter;
};

struct EndStartCount {
    int cc;
    int cv;
    int vc;
    int vv;
};

struct VowsAndConsCnt {
    int cons;
    int vows;
};

class Text
{
private:
    // 9
    std::map<std::u32string, int> wordsCount;
    void countWords(std::ifstream& inFile, Assets& assets);

    // 1
    std::map<char32_t, int> charCount;
    void initCharCount(std::ifstream& inFile, Assets& assets);

    // 2
    std::map<int, int> wordLenCount;
    std::map<int, int> sentenceLenCount;
    void initWordLenCount();
    void initSentenceLenCount(std::ifstream& inFile, Assets& assets);

    // 3 skipped

    // 4
    std::map<std::u32string, int> combsCount;
    void initCombsCount(Assets& assets);

    // 5
    std::map<char32_t, ConVowAltCount> conVowAltCount;
    void initConVowAltCount(Assets& assets);

    // 6
    EndStartCount endStartCount;
    void initEndStartCount(std::ifstream& inFile, Assets& assets);

    // 7
    VowsAndConsCnt threeVowsConsInARow;
    void initThreeVCInARow(Assets& assets);

    // 8 
    int twoVowsConsNeighbors;
    void initTwoVowsConsNeihgbors(std::ifstream& inFile, Assets& assets);

public:
    Text(std::string txtPath);

    // 1
    const std::map<char32_t, int>& getCharCount() const { return this->charCount; }

    // 2
    const std::map<int, int>& getWordLenCount() const { return this->wordLenCount; }
    const std::map<int, int>& getSentenceLenCount() const { return this->sentenceLenCount; }

    // 4
    const std::map<std::u32string, int>& getCombsCount() const { return this->combsCount; }

    // 5
    const std::map<char32_t, ConVowAltCount>& getConVowAltCount() const { return this->conVowAltCount; }

    // 6
    const EndStartCount& getEndStartCount() const { return this->endStartCount; }

    // 7
    const VowsAndConsCnt& getThreeVowsConsInARow() const { return this->threeVowsConsInARow; }

    // 8
    int getTwoVowsConsNeighbors() const { return this->twoVowsConsNeighbors; } 

    // 9 
    const std::map<std::u32string, int>& getWordsCount() const { return this->wordsCount; }
};
