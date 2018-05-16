#include <iostream>
#include <string>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
using std::set;
using std::ifstream;
using std::map;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::istringstream;
using std::cerr;

int main(){
    ifstream inFile("../ex11_3.cpp",inFile.in);
    set<string> exclude = {"using","#include"};
    map<string,size_t> mapWords;
    if(inFile.is_open()){
        string line;
        while(getline(inFile,line)){
            istringstream is(line);
            string word;
            while(is >> word ){
                if(exclude.find(word) == exclude.end()){
                    ++mapWords[word];
                }
            }
        }
    }else{
        cerr << "open file get error!" << errno << endl;
    }

    for(const auto& words : mapWords){
        cout << words.first << " ";
        cout << words.second << " occurse."<<endl;
    }

    inFile.close();
    return 0;

}
