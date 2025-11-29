#include "Text.hpp"
#include <vector>

const vector<int> allChars {
    ' ', 'о', 'е', 'а', 'и', 'т', 'н', 'с', 'р',
    'в', 'л', 'к', 'м', 'д', 'п', 'у', 'я', 'ы',
    'з', 'ь', 'ъ', 'б', 'г', 'ч', 'й', 'х', 'ж', 
    'ю', 'ш', 'ц', 'щ', 'э', 'ф'
};

unordered_map<int, int> Text::getCharPercentage(){
    int totalCnt = 0;

    unordered_map<int, int> res;

    for(int c : allChars){
        res[c] = 0;
    }

    for(int c : allChars){
        res[c] = this->charCount.count(c);
    }
}