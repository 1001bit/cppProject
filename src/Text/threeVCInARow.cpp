#include "../../include/Text.hpp"
#include "../../include/charTypes.hpp"

#include <iostream>
#include <set>
#include <vector>

void Text::initThreeVCInARow(){
    const std::set<char32_t> vows(charTypes.at("vows").begin(), charTypes.at("vows").end());
    const std::set<char32_t> cons(charTypes.at("cons").begin(), charTypes.at("cons").end());

    this->threeVowsConsInARow = {0, 0};

    for (auto& it : this->wordsCount){
        const std::u32string& word = it.first;
        int wordCount = it.second;

        int conStreak = 0;
        int vowStreak = 0;

        for (size_t i = 0; i < word.size(); i++){
            char32_t c = word[i];

            if (vows.contains(c)){
                vowStreak += 1;
            } else {
                vowStreak = 0;
            }

            if (cons.contains(c)){
                conStreak += 1;
            } else {
                conStreak = 0;
            }

            if (vowStreak == 3){
                this->threeVowsConsInARow.vows += wordCount;
                vowStreak = 0;
            }
            if (conStreak == 3){
                this->threeVowsConsInARow.cons += wordCount;
                conStreak = 0;
            }
        }
    }
}
