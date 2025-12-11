#include "Text.hpp"
#include "charTypes.hpp"
#include "utfConvert.hpp"
#include "maskWord.hpp"

#include <set>

void Text::initTwoVowsConsNeihgbors(std::ifstream& inFile){
    const std::set<char32_t> vows(charTypes.at("vows").begin(), charTypes.at("vows").end());
    const std::set<char32_t> cons(charTypes.at("cons").begin(), charTypes.at("cons").end());

    this->twoVowsConsNeighbors = 0;

    std::u32string prevWord = U"";
    std::string word;
    while(inFile >> word){
        std::u32string masked = maskWord(word);
        
        if (prevWord.size() < 2 || masked.size() < 2){
            prevWord = masked;
            continue;
        }

        int prevN = prevWord.size();

        this->twoVowsConsNeighbors +=
        vows.contains(prevWord[prevN-1]) &&
        vows.contains(prevWord[prevN-2]) &&
        cons.contains(masked[0]) &&
        cons.contains(masked[1]); 

        prevWord = masked;
    }
}