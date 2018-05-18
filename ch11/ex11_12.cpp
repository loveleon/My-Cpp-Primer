#include "common.h"

int main(){
    vector<pair<string,int>> vec1;
    vector<pair<string,int>> vec2;
    vector<pair<string,int>> vec3;
    vector<pair<string,int>> vec4;
    string str;
    int iNum;
    while(cin >> str >> iNum){
        vec1.push_back(make_pair(str,iNum));
        vec2.push_back(pair<string,int>(str,iNum));
        vec3.push_back(pair<string,int>{str,iNum});
        vec4.push_back({str,iNum});
    }

    cout << "vec1:" << endl;
    for(const auto &item1 : vec1){
        cout << item1.first << " " << item1.second << endl;
    }

    cout << "vec2:" << endl;
    for(const auto &item2 : vec2){
        cout << item2.first << " " << item2.second << endl;
    }
    cout << "vec3:" << endl;
    for(const auto &item3 : vec3){
        cout << item3.first << " " << item3.second << endl;
    }

    cout << "vec4:" << endl;
    for(const auto &item4 : vec4){
        cout << item4.first << " " << item4.second << endl;
    }

    return 0;
}
