#include "Text.hpp"
#include "charTypes.hpp"
#include "utfConvert.hpp"

#include <set>

void Text::initTwoVowsConsNeihgbors(std::ifstream& inFile){
    const std::set<char32_t> vows(charTypes.at("vows").begin(), charTypes.at("vows").end());
    const std::set<char32_t> cons(charTypes.at("cons").begin(), charTypes.at("cons").end());

    this->twoVowsConsNeighbors = 0;

    std::u32string prevWord = U"";
    std::string word;
    while(inFile >> word){
        std::u32string wordConv = conv.from_bytes(word);
        
        if (prevWord == U""){
            prevWord = wordConv;
            continue;
        }

        int prevN = prevWord.size();

        this->twoVowsConsNeighbors +=
        vows.contains(prevWord[prevN-1]) &&
        vows.contains(prevWord[prevN-2]) &&
        cons.contains(wordConv[0]) &&
        cons.contains(wordConv[1]); 

        prevWord = wordConv;
    }
}