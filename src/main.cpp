//this category focuses on I/O in project category
//also utilizes 2-d vectors instead of maps

/*TODO LIST:

checklist:

1.debug:

filestream usage:false;
eof:false;
char count:false;

2.writing:

memory leak(?)
unreadable symbols
change that the output file is created only using full path(not required here)
sort by usage

*/
/*
Error list:
0 - safe usage
1 - path cannot be opened
2 - error while choosing output mode
*/
#include <iostream> //console i/o
#include <fstream>     //file i/o

#include <string>
#include <vector>   //datatypes
#include <map>
#include <algorithm>    //find & sort

#include "prep.h"
//vector<char>L{' ','\n','\t',':',"'",'"','?','!','.','(',')','-'};
//need a proper name here

using namespace std;


void word_specifier(string word, vector<pair<int,string>>&A, vector<pair<int,string>>&B)
{
    //A is prep, b- word
  //  vector<vector<string>>A=prep();

    bool flag=true;
    for (int i=0; i<size(A); i++)
    if (word==A[i].second)
    {
        flag=false;
        A[i].first++;
        break;
    }
    if (flag==true){
    for (int i=0; i<size(B); i++){
        if (B[i].second==word)
        {
            B[i].first++;
            flag=false;
            break;
        }
    }
    if (flag==true)
    {
        B.resize(size(B)+1);
        B[size(B)-1]={1,word};
    }
}
}

void word_counter(int &_count,string s,int &tot_len, bool &word_flag, int &sen_count){
vector<char>L={' ','.',',','!','?','\'','\"',')','('};
string comp=" .,!?)()";
//vector<char>L={' '}; if the text is correct
//vector<char>L={" ",".","\n","\t",":","?","!","(",")","-"};
bool word_=true;//the next non-L symbol is the one of the word
bool L_n=false;//name change, shows whether the curr symbol doesn't belong to a word

string word;
int word_begin=0;
int word_end=0;
int _min=-1;
word_end=s.find_first_of(comp,word_begin);
while(word_end!=-1)
    {
        word=s.substr(word_begin, word_end-1-word_begin);
        word_begin=word_end+1;
        word_end=s.find_first_of(comp,word_begin);


        //for (int i=0; i)

        _count++;
        tot_len++;
        if (s[word_end]=='.')
        sen_count++;
    }

}






void char_output(vector<vector<int>>A){
for (int i=150; i<256; i++){
    cout<<char(i)<<" "<<A[1][i]<<endl;
}
}

int main()
{
    vector<vector<int>>A(2,vector<int>(256,0));//variable declaration //char table
    vector<vector<string>>Word_list();  //self-explanatory
    vector<pair<int,string>>N=prep(); //preposition table
    string file_input_path,file_output_path,s;
    int mode_switch=1;



    ifstream inFile("assets/inputFile.txt");



    if (inFile.is_open()) {
        while(inFile.eof()!=true){
            getline(inFile,s);
            cout<<s<<endl;
            for(int i=0; i<size(s); i++){
               int curr_symb=int(s[i]);
                A[1][curr_symb]++;
            }


        }
            inFile.close();
    } else {    //if path entered is incorrect
        cout<<"Error: Could not open file at "<< file_input_path<<endl;
        return 1;
    }


    //interface part
    cout<<"Enter 0 to save in a file, or 1 to output to console"<<endl;
    cin>>mode_switch;


switch(mode_switch){
case 0:{

    ofstream outFile("results/outputFile.txt");
    if (outFile.is_open()){
    cout<<"check"<<endl;
    return 0;
    }
    else{
    cout<<"Error: Couldn't open file at/or path is incorrect"<<endl;
    return 1;
    }
}
case 1:{
    char_output(A);
    return 0;
}
}

cout<<"Output mode is not specified"<<endl;
return 2;
}
