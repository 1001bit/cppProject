#include "Text.hpp"
#include "utfConvert.hpp"

#include <codecvt>
#include <fstream>
#include <locale>
#include <locale>


using namespace std;

string toUtf8(char32_t ch) {
    wstring_convert<codecvt_utf8<char32_t>, char32_t> conv;
    return conv.to_bytes(ch);
}

void charsPercentToFile(string path, const unordered_map<char32_t, double>& cnt){
    ofstream outFile(path);

    if(!outFile.is_open()){
        throw runtime_error("Could not open file: " + path);
    }

    for(const auto& it : cnt){
        outFile << toUtf8(it.first) << " : " << it.second << "%\n";
    } 
}


void wordPercentToFile(string path, const unordered_map<int, double>& cnt){
    ofstream outFile(path);

    if(!outFile.is_open()){
        throw runtime_error("Could not open file: " + path);
    }

    for(const auto& it : cnt){
        outFile << it.first << " : " << it.second << "%\n";
    } 
}

int main(){
    //std::setlocale(LC_ALL, "");
    //std::locale::global(std::locale(""));
    Text* test = new Text("input/1.txt");

    unordered_map<char32_t, double> cnt = test->getCharPercentage();
    unordered_map<int,double>count= test->getWordLenPercentage();
    charsPercentToFile("output/1.txt", cnt);
    wordPercentToFile("output/2.txt", count);
}
