#include "Text.hpp"
#include "charTypes.hpp"
#include "utfConvert.hpp"

#include <set>

void Text::initEndStartCount(std::ifstream& inFile){
    this->endStartCount = {0,0,0,0};

    const std::set<char32_t> vows(charTypes.at("vows").begin(), charTypes.at("vows").end());
    const std::set<char32_t> cons(charTypes.at("cons").begin(), charTypes.at("cons").end());

    std::u32string prevWord = U"";
    std::string word;
    while(inFile >> word){
        std::u32string wordConv = conv.from_bytes(word);
        
        if (prevWord == U""){
            prevWord = wordConv;
            continue;
        }

        char32_t prevLast = prevWord[prevWord.size()-1];
        char32_t currFirst = wordConv[0];

        this->endStartCount.cc += cons.contains(prevLast) && cons.contains(currFirst);
        this->endStartCount.cv += cons.contains(prevLast) && vows.contains(currFirst);
        this->endStartCount.vc += vows.contains(prevLast) && cons.contains(currFirst);
        this->endStartCount.vv += vows.contains(prevLast) && vows.contains(currFirst);

        prevWord = wordConv;
    }
}