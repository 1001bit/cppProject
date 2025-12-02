#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Text
{
private:
    unordered_map<char32_t, int> charCount;
    unordered_map<int, int> wordLenCount;
    unordered_map<char32_t, int> sentenceLenCount;

    void countChars(vector<u32string>);
    void countWords(vector<u32string>);

public:
    Text(string txtPath);

    vector<u32string>stringHandler;
    vector<u32string>wordHandler;

    unordered_map<char32_t, double> getCharPercentage();
    unordered_map<int, double> getWordLenPercentage();
    unordered_map<char32_t, double> getSentenceLenPercentage();
};

