#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    SetConsoleOutputCP(1251);//table changes
    SetConsoleCP(1251);
    setlocale(' ',0);
    string s="ô";
    cout<<s;
    return 0;
}