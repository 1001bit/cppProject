#include "Text.hpp"

#include <fstream>
#include <iostream>
#include <vector>

vector<string> strings(ifstream& inFile) {
    string s;
    int i=0;
    vector<string>A;
    while (!inFile.eof()){
    getline(inFile, s);
    i++;
    A.resize(size(A)+1);
    A[i]=s;
    }
    return A;
}


void Text::countChars(vector<string>A){
    for (int i=0; i<size(A); i++){
    string s=A[i];
        for(int j=0; j<size(s); j++){
            this->charCount[s[j]]++;
        }
    }
}

void word(vector<string>A){
        for (int i=0; i<size(A); i++){
    string s=A[i];
        for(int j=0; j<size(s); j++){
            this->charCount[s[j]]++;
        }
    }
}


Text::Text(string txtPath) {
    ifstream inFile(txtPath);
    vector<string>A=strings(inFile);
    if (!inFile.is_open()) {
        throw runtime_error("Could not open file: " + txtPath);
    }

    while (!inFile.eof())
    {
    string curr_s=stringHandler(inFile);
    this->countChars(inFile);
    }
}
