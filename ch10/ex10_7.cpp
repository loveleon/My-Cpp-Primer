#include "common.h"

int main(){
    vector<int> vec;
    list<int> lst;
    int i;
    while(cin >> i){
        lst.push_back(i);
    }

    copy(lst.begin(),lst.end(),std::back_inserter(vec));
    cout << endl;
    for(const auto j : vec){
        cout << j << " ";
    }
    cout << endl;

    cout << "vec2:" << endl;
    vector<int> vec2;
//    vec2.reserve(10);//no sense.
//    vec2.resize(10);
//    std::fill_n(vec2.begin(),10,1);
        std::fill_n(back_inserter(vec2),10,2);
    for(const auto &item : vec2){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
