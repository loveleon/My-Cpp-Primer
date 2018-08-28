#include "find.h"
#include <vector>
#include <list>
#include <string>
#include <iostream>
using std::vector;
using std::list;
using std::string;
using std::cout;using std::endl;

int main(){
    vector<int> vec = {1,2,3,4,5,6};
    list<string> lst = {"str","cxh","hello","world","ni"};

    auto itVec = ex16::find(vec.begin(),vec.end(),4);
    cout << std::boolalpha << (itVec != vec.end()) << " value: " <<*itVec << endl;

    string str("cxh");
    auto is_itLst_found = (lst.cend() != ex16::find(lst.cbegin(),lst.cend(),"cxh"));
    cout << std::boolalpha << is_itLst_found << endl;
    return 0;
}
