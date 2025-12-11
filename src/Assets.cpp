#include "Assets.hpp"
#include "json.hpp"
#include "utfConvert.hpp"

#include <fstream>

using nlohmann::json;

Assets::Assets(std::string charTypesPath, std::string combinationsPath){
    std::ifstream charTypesIn(charTypesPath);
    json charTypesJson = json::parse(charTypesIn);
    std::map<std::string, std::string> charTypesBytes = charTypesJson.get<std::map<std::string, std::string>>();
    for (auto& it : charTypesBytes){
        this->charTypes[it.first] = conv.from_bytes(it.second);
    } 

    std::ifstream combinationsIn(combinationsPath);
    json combinationsJson = json::parse(combinationsIn);
    std::vector<std::string> combinationsBytes = combinationsJson.get<std::vector<std::string>>();
    for (const std::string& s : combinationsBytes){
        this->combinations.push_back(conv.from_bytes(s));
    } 
}