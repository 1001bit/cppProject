#pragma once

#include <map>
#include <string>
#include <vector>

class Assets {
private:
    std::map<std::string, std::u32string> charTypes;
    std::vector<std::u32string> combinations;
public:
    Assets(std::string charTypesPath, std::string combinationsPath);

    const std::map<std::string, std::u32string>& getCharTypes() const { return this->charTypes; }
    const std::vector<std::u32string>& getCombinations() const { return this->combinations; }
};