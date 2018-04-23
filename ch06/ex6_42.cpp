//
// Created by cxh on 18-4-23.
//

#include "comm/comm.h"

string make_plural(size_t ctr, const string& word,const string& ending){
    return (ctr > 1)? word + ending : word;
}

string make_plural(const string& str, string s = "s"){
    return str + s;
}

int main(){
    string str1 = "success";
    string str2 = "failure";
    cout << "success fushu :" << make_plural(str1,"es") << endl;
    cout << "failure fushu :" << make_plural(str2) << endl;

    return 0;
};