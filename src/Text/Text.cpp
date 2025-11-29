#include "Text.hpp"

#include <fstream>
#include <iostream>
#include <string>

void Text::countChars(ifstream& inFile) {
    while(inFile.eof() != true){
        string s;
        getline(inFile, s);

        for(int i = 0; i < s.size(); i++){
            this->charCount[to_string(s[i])]++;
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
