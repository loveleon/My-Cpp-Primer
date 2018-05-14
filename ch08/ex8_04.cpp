#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::vector;
using std::string;
using std::cout;
using std::cin;

void ReadFIle(const string& f){
    std::ifstream ifile(f,ifile.in);
    std::vector<string> vec;
    //if(ifile.is_open()){//all right
    if(ifile){//all right
        while(ifile){
            string tmp;
            getline(ifile,tmp);
            vec.push_back(tmp);
        }
    }
    for(auto str : vec){
        std::cout << str << std::endl;
    }
}

int main(){
    ReadFIle("../ex8_04.cpp");

    return 0;
}
