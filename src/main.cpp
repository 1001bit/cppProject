#include "Text.hpp"
#include <fstream>

void charsPercentToFile(string path, const unordered_map<string, double>& cnt){
    ofstream outFile(path);

    if(!outFile.is_open()){
        throw runtime_error("Could not open file: " + path);
    }

    for(auto& it : cnt){
        outFile << it.first << " : " << it.second << "%\n";
    } 
}

int main(){
    Text* test = new Text("input/1.txt");

    unordered_map<string, double> cnt = test->getCharPercentage();
    charsPercentToFile("output/1.txt", cnt);
}