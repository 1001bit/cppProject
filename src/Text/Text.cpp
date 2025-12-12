#include "Text.hpp"
#include "utfConvert.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

Text::Text(const std::filesystem::path& txtPath) {
    std::ifstream inFile(txtPath);
    if (!inFile.is_open()) {
        throw std::runtime_error("Could not open file: " + txtPath.string());
    }

    Assets assets("assets/charTypes.json", "assets/combinations.json");

    // 9
    this->countWords(inFile, assets);
    inFile.clear(); inFile.seekg(0);

    // 1
    this->initCharCount(inFile, assets);    
    inFile.clear(); inFile.seekg(0);

    // 2
    this->initWordLenCount();
    this->initSentenceLenCount(inFile, assets);
    inFile.clear(); inFile.seekg(0);

    // 4
    this->initCombsCount(assets);

    // 5
    this->initConVowAltCount(assets);
    inFile.clear(); inFile.seekg(0);

    // 6
    this->initEndStartCount(inFile, assets);
    inFile.clear(); inFile.seekg(0);

    // 7
    this->initThreeVCInARow(assets);

    // 8
    this->initTwoVowsConsNeihgbors(inFile, assets);
    inFile.clear(); inFile.seekg(0);
}
