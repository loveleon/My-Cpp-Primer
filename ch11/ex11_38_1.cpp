#include "common.h"
#include <unordered_map>

int main(){
    std::unordered_map<string,size_t> unOrderMap;
    string word;
    while(cin >> word){
        auto ret = unOrderMap.insert({word,1});
        if(!ret.second){
            ++ret.first->second;
        }else{
            cout << "add new" <<endl;
        }

    }

    for(const auto &item : unOrderMap){
        cout << item.first << " " << item.second <<endl;
    }

    return 0;
}
