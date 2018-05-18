#include "common.h"

int main(){
    using Child = pair<string,string>;
    using VEC = vector<Child>;
    VEC vec;
    map<string,VEC> mVec;

    string last_name,first_name,birth;
    cout << "lastname first_name birthday:" << endl;
    while(cin >> last_name >> first_name >> birth){
        mVec[last_name].push_back(make_pair(first_name,birth));
    }

    for(const auto &mm :mVec){
        cout << "family name:" << mm.first  << endl;
        for(const auto &vv : mm.second){
            cout << vv.first << " " << vv.second << endl;
        }
        cout << endl;
    }
    return 0;
}
