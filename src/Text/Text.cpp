#include "Text.hpp"

#include <fstream>
#include <iostream>

void Text::countChars(ifstream& inFile) {
    while(inFile.eof() != true){
        string s;
        getline(inFile, s);

        for(int i=0; i<size(s); i++){
            this->charCount[s[i]]++;
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
