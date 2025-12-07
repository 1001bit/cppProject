#include "Text.hpp"
#include "utfConvert.hpp"

#include <vector>
#include <iostream>

void Text::initCharCount(std::ifstream& inFile){
    std::string line;

    while(getline(inFile, line)){
        std::u32string converted = conv.from_bytes(line);
        for(char32_t c : converted){
            this->charCount[std::towlower(c)]++;
        }
    }
}
