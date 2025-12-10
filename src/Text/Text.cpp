#include "Text.hpp"
#include "utfConvert.hpp"

#include <fstream>
#include <iostream>
#include <string>

Text::Text(std::string txtPath) {
    std::ifstream inFile(txtPath);
    if (!inFile.is_open()) {
        throw std::runtime_error("Could not open file: " + txtPath);
    }

    // 9
    this->countWords(inFile);

    // 5
    this->initConVowAltCount();
    inFile.clear(); inFile.seekg(0);

    // 1
    this->initCharCount(inFile);    
    inFile.clear(); inFile.seekg(0);

    // 2
    this->initWordLenCount();
    this->initSentenceLenCount(inFile);
    inFile.clear(); inFile.seekg(0);

    // 6
    this->initEndStartCount(inFile);
    inFile.clear(); inFile.seekg(0);

    // 7
    this->initThreeVCInARow();

    // 8
    this->initTwoVowsConsNeihgbors(inFile);
    inFile.clear(); inFile.seekg(0);
}
