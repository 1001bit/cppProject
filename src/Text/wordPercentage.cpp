#include "Text.hpp"
#include <vector>
#include <iostream>
#include <map>

unordered_map<int, double> Text::getWordLenPercentage(){
    int totalCount = 0;
    unordered_map<int, double> res{}; 
    for (pair<int,int>a : Text::wordLenCount){
    cout<<a.first<<" "<<a.second<<endl;
    totalCount+=a.second;
    res[a.first]=0;
    }
    cout<<totalCount<<endl;
    if (totalCount==0)
    return res;

    for(pair<int,int>a :Text::wordLenCount){

        res[a.first] = this->wordLenCount[a.second]/totalCount*100.0;
    }

    return res;
}
