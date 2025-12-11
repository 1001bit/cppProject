#include "../include/Text.hpp"

#include <set>

void Text::initCombsCount(){
    const std::vector<std::u32string> combinations{
        U"ст", U"но", U"ен", U"то", U"на", U"ов", U"ни", U"ра", U"во", U"ко",
        U"сто", U"ено", U"нов", U"тов", U"ово", U"ова"
    };

    for (auto& it : this->wordsCount){
        const std::u32string& word = it.first;
        int wordCount = it.second;

        for (auto& comb : combinations){
            this->combsCount[comb] += wordCount * (word.find(comb) != std::u32string::npos);
        }
    }
}
