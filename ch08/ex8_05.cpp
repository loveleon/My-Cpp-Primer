#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::string;
using std::vector;
using std::ifstream;

void ReadFile(const string& sfile,vector<string>& vec){
    ifstream ifile(sfile,ifile.in);
    if(ifile){
        string tmp;
        while(ifile >> tmp){
            vec.push_back(tmp);
        }
    }
}

int main(){

    vector<string> vec;
    ReadFile("../ex8_05.cpp",vec);
    for(auto& str:vec){
        std::cout << str << std::endl;
    }

    return 0;
}
