#pragma once

#include <fstream>
#include <map>
#include <string>
#include <vector>

extern const std::map<std::string, std::u32string> charTypes;

struct AltCount {
    int conBefore;
    int conAfter;
    int vowBefore;
    int vowAfter;
};

class Text
{
private:
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
    std::map<char32_t, AltCount> altCount;
    void initAltCount(std::ifstream& inFile);

public:
    Text(std::string txtPath);

    // 1
    const std::map<char32_t, int>& getCharCount() const { return this->charCount; }

    // 2
    const std::map<int, int>& getWordLenCount() const { return this->wordLenCount; }
    const std::map<int, int>& getSentenceLenCount() const { return this->sentenceLenCount; }

    // 5
    const std::map<char32_t, AltCount>& getAltCount() const { return this->altCount; }

    // 9
    const std::vector<std::pair<std::u32string, int>> getTopWords() const;
};
