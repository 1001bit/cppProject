#include "../include/maskWord.hpp"

std::u32string maskWord(std::string word){
    std::u32string res = U"";
    std::set<char32_t> letters(charTypes.at("letters").begin(), charTypes.at("letters").end());

    for(char32_t c : conv.from_bytes(word)){
        c = towlower(c);
        if (letters.contains(c) || c == U'-'){
            res += c;
        }
    }

    return res;
}
