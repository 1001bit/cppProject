#include "textToJson.hpp"
#include "utfConvert.hpp"

std::map<std::string, std::map<std::string, double>> textCharStats(const Text& text){
    std::map<std::string, std::map<std::string, double>> res;

    for(auto& it : text.getCharStats()){
        const std::string& type = it.first;
        const std::map<char32_t, double>& stats = it.second;
        std::map<std::string, double> newStats;
        
        for(auto& it1 : stats){
            const std::string c = conv.to_bytes(it1.first);
            const double percent = it1.second;
            newStats[c] = percent;
        }

        res[type] = newStats;
    }

    return res;
}

std::map<std::string, std::map<std::string, AltStats>> textAltStats(const Text& text){
    std::map<std::string, std::map<std::string, AltStats>> res{
        {"vowels", {}},
        {"consonants", {}}
    };
    
    for (auto& it : text.getVowAltStats()) {
        char32_t c = it.first;
        const AltStats& s = it.second;

        res["vowels"][conv.to_bytes(c)] = s;
    }

    for (auto& it : text.getConAltStats()) {
        char32_t c = it.first;
        const AltStats& s = it.second;

        res["consonants"][conv.to_bytes(c)] = s;
    }

    return res; 
}

void to_json(nlohmann::json& j, const AltStats& stats){
    j = std::map<std::string, double>{
        {"conBefore", stats.conBefore},
        {"vowBefore", stats.vowBefore},
        {"conAfter", stats.conAfter},
        {"vowAfter", stats.vowAfter},
    };
}

void to_json(nlohmann::json& j, const Text& text) {
    json obj = json::object();

    obj["charStats"] = textCharStats(text);
    obj["altStats"] = textAltStats(text);

    j = obj;
}
