#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Text
{
private:
    unordered_map<int, int> charCount;
    unordered_map<int, int> wordLenCount;
    unordered_map<int, int> sentenceLenCount;

    void countChars(vector<string>);
    void word(string);

public:
    Text(string txtPath);
    vector<string>stringHandler();
    vector<string>wordHandler();
    unordered_map<int, int> getCharPercentage();
    unordered_map<int, int> getWordLenPercentage();
    unordered_map<int, int> getSentenceLenPercentage();
};

