#include "common.h"

void print(vector<string> &vec){
    cout << "print(vec): ";
    for(const auto item : vec){
        cout << item << " ";
    }
    cout << endl;
}
bool isShorter(const string &str1, const string &str2){
    if(str1.size() < str2.size()){
        return true;
    }else{
        return false;
    }
}

void elimDups(vector<string> &vec){
    std::sort(vec.begin(),vec.end());
    auto eniqu_it = std::unique(vec.begin(),vec.end());
    vec.erase(eniqu_it,vec.end());
}

