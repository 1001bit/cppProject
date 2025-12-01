#pragma once

#include <codecvt>
#include <locale>
#include <string>

extern std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
