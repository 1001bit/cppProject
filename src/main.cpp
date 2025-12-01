#include "Text.hpp"
#include "utfConvert.hpp"
#include "textToJson.hpp"

#include <fstream>

int main(){
    Text* test = new Text("input/1.txt");
    json testJson = *test;

    std::ofstream outFile("output/1.json");
    outFile << testJson.dump(2);
}
