#include "maskWord.hpp"
#include <iostream>

std::u32string maskWord(std::string word, std::u32string allowed){
    std::u32string res = U"";

    for(char32_t c : conv.from_bytes(word)){
        c = towlower(c);

        if (allowed.find(c) != std::u32string::npos){
            res += c;
        }
    }

    return res;
}