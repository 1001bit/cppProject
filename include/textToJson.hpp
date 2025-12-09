#include "json.hpp"
#include "Text.hpp"

using nlohmann::json;

void to_json(nlohmann::json& j, const Text& text);
void to_json(nlohmann::json& j, const ConVowAltCount& cnt);