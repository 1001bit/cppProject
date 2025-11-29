#include <unordered_map>
#include <string>

using namespace std;

class Text
{
private:
    unordered_map<string, int> charCount;
    // TODO:
    // unordered_map<int, int> wordLenCount;
    // unordered_map<int, int> sentenceLenCount;

    void countChars(ifstream& inFile);

public:
    Text(string txtPath);

    unordered_map<string, double> getCharPercentage();
    // TODO:
    // unordered_map<int, int> getWordLenPercentage();
    // unordered_map<int, int> getSentenceLenPercentage();
};

