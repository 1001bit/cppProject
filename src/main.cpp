#include "../include/Text.hpp"
#include "../include/utfConvert.hpp"
#include "../include/textToJson.hpp"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <locale>

namespace fs = std::filesystem;

int main(){
    std::setlocale(LC_ALL, "");
    try {
        std::locale::global(std::locale(""));
    } catch (const std::runtime_error&) {
        // Locale not available, using default C locale
    }

    for(const auto& entry : fs::directory_iterator("input")){
        Text text(entry.path().string());
        json textJson = text;

        fs::path outPath = fs::path("output") / entry.path().filename();
        outPath.replace_extension(".json");

        std::ofstream outFile(outPath);
        outFile << textJson.dump(2);
    }
}
