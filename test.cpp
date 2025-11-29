#include <fstream>
#include <iostream>
#include <windows.h>
#include <map>
#include <string>
#include <vector>
using namespace std;

//#pragma once

int main(){
    //SetConsoleOutputCP(1251);//table changes
    //SetConsoleCP(1251);
    string s="a";
    //map<string,int>A={{"-11",0}};
    //map<string,int>prep_map;
    vector<vector<string>>A;
    ifstream inp_file("prep.txt");
    if(inp_file.is_open())
    {
        while(inp_file.eof()==false)
        {
            //getline(inp_file,s);
            A.resize(size(A)+1);
            //prep_map.insert(pair<string,int>{s,0});
            A[size(A)-1][0]=s;
            A[size(A)-1][1]="0";
        }
    }
    else
    {
        cout<<"Input file is missing, please insert file prep.txt"<<endl;
        return 0;
    }
    return 0;
}