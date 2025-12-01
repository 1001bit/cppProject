#include "Text.hpp"
#include "utfConvert.hpp"

#include <vector>
#include <iostream>

const std::unordered_map<std::string, std::vector<char32_t>> charTypes {
    {
        "all", 
        {
            U'а', U'б', U'в', U'г', U'д', U'е', U'ё', U'ж', U'з', U'и', U'й', U'к',
            U'л', U'м', U'н', U'о', U'п', U'р', U'с', U'т', U'у', U'ф', U'х', U'ц',
            U'ч', U'ш', U'щ', U'ъ', U'ы', U'э', U'ю', U'я',

            ' ', ',', '.', '!', '?', ';', ':'
        }
    }
};

std::unordered_map<char32_t, int> getCharCount(std::ifstream& inFile){
    std::unordered_map<char32_t, int> charCount;
    std::string line;

    while(getline(inFile, line)){
        std::u32string converted = conv.from_bytes(line);
        for(char32_t c : converted){
            charCount[std::towlower(c)]++;
        }
    }

    return charCount;
}

void Text::initCharStats(std::ifstream& inFile){
    std::unordered_map<char32_t, int> charCount = getCharCount(inFile);

    std::unordered_map<std::string, std::unordered_map<char32_t, double>>& charStats = this->charStats;

    for(auto& it : charTypes){
        const std::string& type = it.first;
        const std::vector<char32_t>& chars = it.second;
        double totalCnt = 0;

        for(char32_t c : chars){
            totalCnt += charCount[c];
            charStats[type][c] = 0;
        }

        if(totalCnt == 0){
            break;
        }

        for(char32_t c : chars){
            charStats[type][c] = charCount[c]/totalCnt;
        }
    }
}
