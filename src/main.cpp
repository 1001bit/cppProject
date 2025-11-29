#include "Text.hpp"

#include <codecvt>
#include <fstream>
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

int main(){
    Text* test = new Text("input/1.txt");

    unordered_map<char32_t, double> cnt = test->getCharPercentage();
    charsPercentToFile("output/1.txt", cnt);
}
