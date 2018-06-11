#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <functional>
#include "ex12_32.h"

using std::vector;using std::map;using std::istringstream;using std::ifstream;using std::cout;using std::cin;using std::endl;
using std::string;using std::set;

int main(){
    ifstream infile("../ex12_28.cpp",infile.in);
    if(!infile){
        std::cerr << "Open file error! " << endl;
        return -1;
    }

    vector<string> vFile{};
    map<string,set<int>> mWordLine{};
    int nLineNo = 0;
    //int nLineNo = 1;
    for(string line;std::getline(infile,line);++nLineNo){
        vFile.push_back(line);
        istringstream is(line);
        for(string text,word;is >> text; word.clear()){
            std::remove_copy_if(text.begin(),text.end(),std::back_inserter(word),ispunct);
            auto &newset = mWordLine[word];
            newset.insert(nLineNo);
        }
    }

    cout << "lookup" << endl;
    for(string msg;cin >> msg;cout << "going on lookup..."){
        if(msg == string("q") || msg == string("Q")){
            break;
        }
        auto it = mWordLine.find(msg);
        if(it != mWordLine.end()){
        auto times =  it->second.size();
        cout << it->first << " ocur " <<times << (times > 1?" times":" time") << endl;
        for(auto item : it->second){
           // cout << "   (line " << ++item << ") " <<  vFile[--std::ref(item)] << endl;
            cout << "   (line " << item+1 << ") " <<  vFile.at(item) << endl;//nLineNo start 0
        }
        cout << endl;
        }else{
            cout << "can't find " << msg << endl;
        }
    }
    return 0;
}
