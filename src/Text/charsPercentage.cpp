#include "Text.hpp"
#include <vector>
#include <iostream>

const std::vector<char32_t> neededChars {
    U'а', U'б', U'в', U'г', U'д', U'е', U'ё', U'ж', U'з', U'и', U'й', U'к',
    U'л', U'м', U'н', U'о', U'п', U'р', U'с', U'т', U'у', U'ф', U'х', U'ц',
    U'ч', U'ш', U'щ', U'ъ', U'ы', U'э', U'ю', U'я',

    ' ', ',', '.', '!', '?', ';', ':'
};

std::unordered_map<char32_t, double> Text::getCharPercentage(){
    double totalCnt = 0;

    std::unordered_map<char32_t, double> res;

    for(char32_t c : neededChars){
        totalCnt += this->charCount[c];
        res[c] = 0;
    }

    if(totalCnt == 0){
        return res;
    }

    for(char32_t c : neededChars){
        res[c] = this->charCount[c]/totalCnt*100.0;
    }

    return res;
}
