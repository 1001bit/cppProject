#include "Text.hpp"
#include "utfConvert.hpp"
#include "maskWord.hpp"

#include <set>

void Text::initEndStartCount(std::ifstream& inFile, Assets& assets){
    this->endStartCount = {0,0,0,0};

    const std::map<std::string, std::u32string>& charTypes = assets.getCharTypes();

    const std::set<char32_t> vows(charTypes.at("vows").begin(), charTypes.at("vows").end());
    const std::set<char32_t> cons(charTypes.at("cons").begin(), charTypes.at("cons").end());

    std::u32string prevWord = U"";
    std::string word;
    while(inFile >> word){
        std::u32string masked = maskWord(word, charTypes.at("letters") + U'-');
        
        if (prevWord == U""){
            prevWord = masked;
            continue;
        }

        char32_t prevLast = prevWord[prevWord.size()-1];
        char32_t currFirst = masked[0];

        this->endStartCount.cc += cons.contains(prevLast) && cons.contains(currFirst);
        this->endStartCount.cv += cons.contains(prevLast) && vows.contains(currFirst);
        this->endStartCount.vc += vows.contains(prevLast) && cons.contains(currFirst);
        this->endStartCount.vv += vows.contains(prevLast) && vows.contains(currFirst);

        prevWord = masked;
    }
}