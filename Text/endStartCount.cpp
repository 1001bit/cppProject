#include "../include/Text.hpp"
#include "../include/charTypes.hpp"
#include "../include/utfConvert.hpp"
#include "../include/maskWord.hpp"

#include <set>

void Text::initEndStartCount(std::ifstream& inFile){
    this->endStartCount = {0,0,0,0};

    const std::set<char32_t> vows(charTypes.at("vows").begin(), charTypes.at("vows").end());
    const std::set<char32_t> cons(charTypes.at("cons").begin(), charTypes.at("cons").end());

    std::u32string prevWord = U"";
    std::string word;
    while(inFile >> word){
        std::u32string masked = maskWord(word);

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
