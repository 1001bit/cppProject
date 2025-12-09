#pragma once

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
    void countWords(std::ifstream& inFile);

    // 1
    std::map<char32_t, int> charCount;
    void initCharCount(std::ifstream& inFile);

    // 2
    std::map<int, int> wordLenCount;
    std::map<int, int> sentenceLenCount;
    void initWordLenCount();
    void initSentenceLenCount(std::ifstream& inFile);

    // 5
    std::map<char32_t, ConVowAltCount> conVowAltCount;
    void initConVowAltCount();

    // 6
    EndStartCount endStartCount;
    void initEndStartCount(std::ifstream& inFile);

    // 7
    VowsAndConsCnt threeVowsConsInARow;
    void initThreeVCInARow();

public:
    Text(std::string txtPath);

    // 1
    const std::map<char32_t, int>& getCharCount() const { return this->charCount; }

    // 2
    const std::map<int, int>& getWordLenCount() const { return this->wordLenCount; }
    const std::map<int, int>& getSentenceLenCount() const { return this->sentenceLenCount; }

    // 5
    const std::map<char32_t, ConVowAltCount>& getConVowAltCount() const { return this->conVowAltCount; }

    // 6
    const EndStartCount& getEndStartCount() const { return this->endStartCount; }

    // 7
    const VowsAndConsCnt& getThreeVowsConsInARow() const { return this->threeVowsConsInARow; }

    // 9 
    const std::map<std::u32string, int>& getWordsCount() const { return this->wordsCount; }
};