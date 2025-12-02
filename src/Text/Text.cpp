#include "Text.hpp"
#include "utfConvert.hpp"


#include <fstream>
#include <iostream>
#include <vector>
#include <locale>
#include <string>
#include <codecvt>

/*
TODO
1.create a void responsible for
*/


vector<u32string> strings(ifstream& inFile) {
    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv; //fix: accesing out_of_bounds
    string line;
    int i=0;
    vector<u32string>A={};
    while(getline(inFile, line)){
            u32string converted = conv.from_bytes(line);
            A.resize(size(A)+1);
            A[i]=converted;
            i++;
        }
    return A;
    }


void Text::countChars(vector<u32string>A){
    for (int i=0; i<size(A); i++){
    u32string s=A[i];
        for(int j=0; j<size(s); j++){
            this->charCount[s[j]]++;
        }
    }
}

void Text::countWords(vector<u32string>A){
        vector<u32string>word_list;
        ofstream o("test.txt", ios::app);
        vector<char32_t> B={' ', ',', '.', '!', '?', ';', ':'};
        u32string P=U" ,.!?;:-()";
        //P+=U'"';
        int word_begin;
        int word_end;
        int _min;
        u32string leftover_string;
        string _curr="0";
        for (int i=0; i<size(A); i++){
            //cout<<size(A[i])<<endl;
            u32string s=A[i];
            word_begin=0;
            while(s.find_first_of(P)==word_begin)
            {
                s.erase(word_begin);
            }
            word_end=0;
            word_end=s.find_first_of(P,word_begin);
            while (word_end!=-1)
            {
            while(s.find_first_of(P)==word_begin)
            {
            s.erase(word_begin);
            if(word_end!=0)
            word_end--;
            }
            this->wordHandler.resize(size(this->wordHandler)+1);
            wordHandler[size(wordHandler)-1]=s.substr(word_begin, word_end-word_begin);  //does not require string, needs size instead
            int siz=word_end-word_begin;
            if (siz>0){
            u32string check=s.substr(word_begin, word_end-word_begin);//check

            o<<conv.to_bytes(check)<<siz<<endl;

            if (this->wordLenCount.count(siz)>0)
            this->wordLenCount[siz]++;
            else
           this->wordLenCount.insert(pair<int,int>{siz,1});
            }
            word_begin=word_end+1;
            word_end=s.find_first_of(P,word_begin);
            }
            //leftover_string=s.substr(word_begin,siz-word_begin-1);
        }  
    }


Text::Text(string txtPath) {
    ifstream inFile(txtPath);
    vector<u32string>A=strings(inFile);
    stringHandler=A;
    if (!inFile.is_open()) {
        throw runtime_error("Could not open file: " + txtPath);
    }

    this->countChars(stringHandler);
    this->countWords(stringHandler);
}

/*
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
*/