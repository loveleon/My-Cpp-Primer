#include "common.h"

int main(){
//    multimap<string,vector<string>> multiMap = {{"chen","dong"},{"chen","xi"},{"chen","nan"},{"zhang","dong"},{"zhang","xi"},{"wang","dong"},{"wang","xi"},{"zhao","dong"}};
    multimap<string,vector<string>> multiMap ;
    string X,M;
    while( cin >> X >> M ){
        multiMap.insert(make_pair(X,vector<string>{M}));
    }

    for(const auto &item : multiMap){
        cout << item.first << " ";
        for(const auto &nm : item.second){
            cout << nm << " ";
        }
        cout << endl;
    }

    return 0;
}
