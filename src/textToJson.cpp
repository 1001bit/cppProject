#include "Text.hpp"
#include "utfConvert.hpp"

std::map<std::string, int> textCharCount(const Text& text){
    const std::map<char32_t, int>& cnt = text.getCharCount();
    std::map<std::string, int> res;
    
    for(auto& it : cnt){
        const std::string c = conv.to_bytes(it.first);
        res[c] = it.second;
    }

    return res;
}

std::map<std::string, AltCount> textAltCount(const Text& text){
    std::map<std::string, AltCount> res;
    
    for (auto& it : text.getAltCount()) {
        char32_t c = it.first;
        const AltCount& s = it.second;

        res[conv.to_bytes(c)] = s;
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
    obj["altCnt"] = textAltCount(text);
    obj["wordsCount"] = textWordsCount(text);
    obj["wordSizeCount"] = text.getWordLenCount();
    obj["sentenceLenCount"] = text.getSentenceLenCount();

    // TODO: Words/sentence len

    j = obj;
}

void to_json(nlohmann::json& j, const AltCount& cnt){
    j = std::map<std::string, int>{
        {"conBefore", cnt.conBefore},
        {"vowBefore", cnt.vowBefore},
        {"conAfter", cnt.conAfter},
        {"vowAfter", cnt.vowAfter},
    };
}

