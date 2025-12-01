#include "Text.hpp"
#include "utfConvert.hpp"

#include <fstream>
#include <iostream>
#include <string>

void Text::countChars(std::ifstream& inFile) {
    std::string line;

    while(getline(inFile, line)){
        std::u32string converted = conv.from_bytes(line);
        for(char32_t c : converted){
            this->charCount[tolower(c)]++;
        }
    }
}

Text::Text(std::string txtPath) {
    std::ifstream inFile(txtPath);

    if (!inFile.is_open()) {
        throw std::runtime_error("Could not open file: " + txtPath);
    }

    this->countChars(inFile);
}
