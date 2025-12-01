#include "Text.hpp"
#include "utfConvert.hpp"

#include <fstream>

void charsPercentToFile(std::string path, const std::unordered_map<char32_t, double>& cnt){
    std::ofstream outFile(path);

    if(!outFile.is_open()){
        throw std::runtime_error("Could not open file: " + path);
    }

    for(const auto& it : cnt){
        outFile << conv.to_bytes(it.first) << " : " << it.second << "%\n";
    } 
}

int main(){
    Text* test = new Text("input/1.txt");

    std::unordered_map<char32_t, double> cnt = test->getCharPercentage();
    charsPercentToFile("output/1.txt", cnt);
}
