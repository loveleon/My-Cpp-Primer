#include "common.h"

int main(){
    vector<char *> vec;//= {'abc',"bcd"};
    list<char *> lst;// = {"abc","bcd"};
//    char * tmp = NULL;
    string str1,str2;
    while(cin >> str1 >> str2){
        vec.push_back(const_cast<char *>(str1.c_str()));
        lst.push_back(const_cast<char *>(str2.c_str()));
        cout << str1 << endl;
    }
    auto ret = std::equal(vec.cbegin(),vec.cend(),lst.cbegin());
    cout << std::boolalpha << ret << endl;
    return 0;
}
