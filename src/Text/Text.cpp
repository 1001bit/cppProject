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

    this->initCharCount(inFile);

    inFile.clear();
    inFile.seekg(0);

    this->initAltCount(inFile);

    inFile.clear();
    inFile.seekg(0);

    this->countWords(inFile);
}
