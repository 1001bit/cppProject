#include "textToJson.hpp"
#include "utfConvert.hpp"

std::unordered_map<std::string, std::unordered_map<std::string, double>> textCharStats(const Text& text){
    std::unordered_map<std::string, std::unordered_map<std::string, double>> res;

    for(auto& it : text.getCharStats()){
        const std::string& type = it.first;
        const std::unordered_map<char32_t, double>& stats = it.second;
        std::unordered_map<std::string, double> newStats;
        
        for(auto& it1 : stats){
            const std::string c = conv.to_bytes(it1.first);
            const double percent = it1.second;
            newStats[c] = percent;
        }

        res[type] = newStats;
    }

    return res;
}

void to_json(nlohmann::json& j, const Text& text) {
    json obj = json::object();

    obj["charStats"] = textCharStats(text);

    j = obj;
}
