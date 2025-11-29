#include "Text.hpp"

#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

void Text::countChars(ifstream& inFile) {
    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
    string line;

    while(getline(inFile, line)){
        u32string converted = conv.from_bytes(line);
        for(char32_t c : converted){
            this->charCount[tolower(c)]++;
        }
    }
}

Text::Text(string txtPath) {
    ifstream inFile(txtPath);

    if (!inFile.is_open()) {
        throw runtime_error("Could not open file: " + txtPath);
    }

    this->countChars(inFile);
}
