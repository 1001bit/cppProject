#include "Text.hpp"
#include "utfConvert.hpp"

void Text::initWordLenCount(){
    for (auto& it : this->wordsCount){
        this->wordLenCount[it.first.size()] += it.second;
    }
}

// TODO
void Text::initSentenceLenCount(std::ifstream& inFile){
    std::string line;
    
    while(getline(inFile, line)){
        std::u32string lineConv = conv.from_bytes(line);
    }
}