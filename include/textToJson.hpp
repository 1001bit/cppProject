#pragma once

#include "Text.hpp"
#include "json.hpp"

using nlohmann::json;

void to_json(nlohmann::json& j, const AltStats& stats);
void to_json(nlohmann::json& j, const Text& text);
