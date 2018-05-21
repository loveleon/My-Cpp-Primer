#include "common.h"

int main(){
    map<string,size_t> mWordCount;
    string word;
    while(cin >> word ){
        auto ret = mWordCount.insert({word,1});
        if(!ret.second){
            ++mWordCount[word];
        }else{
            cout << " add new" << endl;
        }
    }

    for(const auto &item : mWordCount){
        cout << item.first << " " << item.second << endl;
    }
    cout << endl;
    return 0;
}
