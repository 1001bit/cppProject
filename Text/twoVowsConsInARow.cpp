#include "../include/Text.hpp"
#include "../include/utfConvert.hpp"
#include "../include/charTypes.hpp"
#include "../include/maskWord.hpp"

#include <set>

void Text::initTwoVowsConsNeihgbors(std::ifstream& inFile){
    const std::set<char32_t> vows(charTypes.at("vows").begin(), charTypes.at("vows").end());
    const std::set<char32_t> cons(charTypes.at("cons").begin(), charTypes.at("cons").end());

    this->twoVowsConsNeighbors = 0;

    std::u32string prevWord = U"";
    std::string word;
    while(inFile >> word){
        std::u32string masked = maskWord(word);

        if (prevWord == U""){
            prevWord = masked;
            continue;
        }

        int prevN = prevWord.size();

        this->twoVowsConsNeighbors +=
        vows.count(prevWord[prevN-1]) &&
        vows.count(prevWord[prevN-2]) &&
        cons.count(masked[0]) &&
        cons.count(masked[1]);

        prevWord = masked;
    }
}
