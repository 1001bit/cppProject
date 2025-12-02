#include "Text.hpp"

#include <algorithm>

const std::vector<std::pair<std::u32string, int>> Text::getTopWords() const{
    std::vector<std::pair<std::u32string, int>> res;
    for(auto& it : this->wordsCount){
        res.push_back(it);
    }

    std::sort(res.begin(), res.end(), [](const std::pair<std::u32string,int> &left, const std::pair<std::u32string,int> &right) {
        return left.second > right.second;
    });

    return res;
}