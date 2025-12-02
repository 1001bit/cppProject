#include "Text.hpp"

const std::map<std::string, std::u32string> charTypes {
    {
        "all", 
        U"абвгдеёжзийклмнопрстуфхцчшщъыьэюя ,.!?:;"
    },
    {
        "letters",
        U"абвгдеёжзийклмнопрстуфхцчшщъыьэюя"
    },
        {
        "vows",
        U"аоуэыяёюеи"
    },
    {
        "cons",
        U"бвгджзйклмнпрстфхцчшщ"
    },
    {
        "voiced",
        U"бвгджзлмнр"
    },
    {
        "voiceless",
        U"пфктшсхцчщ"
    },
    {
        "rare",
        U"фхцчшщж"
    },
    {
        "other",
        U"ьъый"
    },
    {
        "punct",
        U",.!?:;"
    }
};