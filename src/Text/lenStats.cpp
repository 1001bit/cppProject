#include "Text.hpp"
#include "utfConvert.hpp"

#include <set>

void Text::initWordLenCount(){
    for (auto& it : this->wordsCount){
        this->wordLenCount[it.first.size()] += it.second;
    }
}

void Text::initSentenceLenCount(std::ifstream& inFile){
    std::string word;
    int sentenceLen = 0;

    std::set<char> punct{'!', '.', '?'};
    
    while(inFile >> word){
        sentenceLen++;
        if (punct.contains(word[word.size()-1])) {
            this->sentenceLenCount[sentenceLen]++;
            sentenceLen = 0;
        }
    }
    this->sentenceLenCount[sentenceLen]++;
}