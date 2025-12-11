#include "include/Text.hpp"
#include "include/utfConvert.hpp"
#include "include/textToJson.hpp"

void to_json(nlohmann::json& j, const ConVowAltCount& cnt){
    j = std::map<std::string, int>{
        {"conBefore", cnt.conBefore},
        {"vowBefore", cnt.vowBefore},
        {"conAfter", cnt.conAfter},
        {"vowAfter", cnt.vowAfter},
    };
}

void to_json(nlohmann::json& j, const EndStartCount& cnt){
    j = std::map<std::string, int>{
        {"conCon", cnt.cc},
        {"conVow", cnt.cv},
        {"vowCon", cnt.vc},
        {"vowVow", cnt.vv},
    };
}

void to_json(nlohmann::json& j, const VowsAndConsCnt& cnt){
    j = std::map<std::string, int>{
        {"cons", cnt.cons},
        {"vows", cnt.vows}
    };
}

std::map<std::string, int> textCharCount(const Text& text){
    const std::map<char32_t, int>& cnt = text.getCharCount();
    std::map<std::string, int> res;

    for(auto& it : cnt){
        const std::string c = conv.to_bytes(it.first);
        res[c] = it.second;
    }

    return res;
}

std::map<std::string, ConVowAltCount> textConVowAltCount(const Text& text){
    std::map<std::string, ConVowAltCount> res;

    for (auto& it : text.getConVowAltCount()) {
        char32_t c = it.first;
        const ConVowAltCount& s = it.second;

        res[conv.to_bytes(c)] = s;
    }

    return res;
}

std::map<std::string, int> textCombsCount(const Text& text){
    std::map<std::string, int> res;
    for (auto& it : text.getCombsCount()){
        res[conv.to_bytes(it.first)] = it.second;
    }
    return res;
}


std::map<std::string, int> textWordsCount(const Text& text){
    std::map<std::string, int> res;

    for (auto& it : text.getWordsCount()){
        res[conv.to_bytes(it.first)] = it.second;
    }
    return res;
}

void to_json(nlohmann::json& j, const Text& text) {
    json obj = json::object();

    obj["charCnt"] = textCharCount(text);
    obj["conVowAltCount"] = textConVowAltCount(text);
    obj["wordsCount"] = textWordsCount(text);
    obj["wordSizeCount"] = text.getWordLenCount();
    obj["sentenceLenCount"] = text.getSentenceLenCount();
    obj["conVowEndStartCount"] = text.getEndStartCount();
    obj["threeVowsOrConsInARow"] = text.getThreeVowsConsInARow();
    obj["twoVowsConsNeighbors"] = text.getTwoVowsConsNeighbors();
    obj["combinationsCount"] = textCombsCount(text);

    j = obj;
}
