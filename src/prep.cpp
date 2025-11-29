#include "prep.h"
#include <fstream>
#include <iostream>
#include <map>

vector<pair<int,string>> prep(){
    string s="a";
    //map<string,int>A={{"-11",0}};
    //map<string,int>prep_map;
    vector<pair<int,string>>A;
    ifstream inp_file("assets/prep.txt");
    if(inp_file.is_open())
    {
        while(inp_file.eof()==false)
        {
            getline(inp_file,s);
            A.resize(size(A)+1);
            //prep_map.insert(pair<string,int>{s,0});
            A[size(A)-1].first=0;
            A[size(A)-1].second=s;
        }
    }
    else
    {
        cout<<"Input file is missing, please insert file prep.txt"<<endl;
        return {{0,"0"}};
    }
    return A;
}