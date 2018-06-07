#include <iostream>
#include <string>
#include <cstring>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(){
    string line;
    cin >> line;
    char * str = new char [line.size()+1]();
    strcpy(str,line.c_str());
    cout << str << endl;
    delete []str;
    return 0;
}
