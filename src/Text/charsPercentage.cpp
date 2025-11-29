#include "Text.hpp"
#include <vector>

const vector<string> neededChars {
    "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к",
    "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц",
    "ч", "ш", "щ", "ъ", "ы", "э", "ю", "я",

    " ", ",", ".", "!", "?", ";", ":"
};

unordered_map<string, double> Text::getCharPercentage(){
    double totalCnt = 0;

    unordered_map<string, double> res;

    for(string c : neededChars){
        totalCnt += this->charCount.count(c);
        res[c] = 0;
    }

    for(string c : neededChars){
        res[c] = this->charCount.count(c)/totalCnt*100.0;
    }

    return res;
}