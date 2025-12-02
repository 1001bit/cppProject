#include "textToJson.hpp"
#include "utfConvert.hpp"

std::map<std::string, double> textCharStats(const Text& text){
    const std::map<char32_t, double>& stats = text.getCharStats();
    std::map<std::string, double> res;
    
    for(auto& it1 : stats){
        const std::string c = conv.to_bytes(it1.first);
        const double percent = it1.second;
        res[c] = percent;
    }

    return res;
}

std::map<std::string, AltStats> textAltStats(const Text& text){
    std::map<std::string, AltStats> res;
    
    for (auto& it : text.getAltStats()) {
        char32_t c = it.first;
        const AltStats& s = it.second;

        res[conv.to_bytes(c)] = s;
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
