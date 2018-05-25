#include "common.h"

int main(){
    list<string> lst;
    string str;
    string sCountStr;
    while(cin >> str){
        lst.push_back(str);
    }

    cin.clear();
    cout << "input a test string:" << endl;
    cin >> sCountStr;
    auto slist = std::count(lst.cbegin(),lst.cend(),sCountStr);
    cout << "times:" << slist << endl;
    return 0;
}
