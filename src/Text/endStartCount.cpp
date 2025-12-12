#include "Text.hpp"
#include "utfConvert.hpp"
#include "maskWord.hpp"

#include <algorithm>
#include <set>

void Text::initEndStartCount(std::ifstream& inFile, Assets& assets){
    this->endStartCount = {0,0,0,0};

    const std::map<std::string, std::u32string>& charTypes = assets.getCharTypes();

    const std::set<char32_t> vows(charTypes.at("vows").begin(), charTypes.at("vows").end());
    const std::set<char32_t> cons(charTypes.at("cons").begin(), charTypes.at("cons").end());
    const std::set<char32_t> letters(charTypes.at("letters").begin(), charTypes.at("letters").end());

    std::u32string prevWord = U"";
    std::string word;
    while(inFile >> word){
        std::u32string masked = maskWord(word, charTypes.at("letters") + U'-');

        const bool hasLetters = std::any_of(masked.begin(), masked.end(), [&](char32_t c){
            return letters.count(c);
        });
        if (!hasLetters){
            continue;
        }
        
        if (prevWord == U""){
            prevWord = masked;
            continue;
        }

        char32_t prevLast = prevWord[prevWord.size()-1];
        char32_t currFirst = masked[0];

        this->endStartCount.cc += cons.count(prevLast) && cons.count(currFirst);
        this->endStartCount.cv += cons.count(prevLast) && vows.count(currFirst);
        this->endStartCount.vc += vows.count(prevLast) && cons.count(currFirst);
        this->endStartCount.vv += vows.count(prevLast) && vows.count(currFirst);

        prevWord = masked;
    }
}
