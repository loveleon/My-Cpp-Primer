#include "common.h"

int main(){
    multimap<string,string> mAuthorProd;
    string autor,book;
    while(cin >> autor >> book){
        mAuthorProd.insert({autor,book});
    }

    map<string,multiset<string>> orderMap;
    for(const auto &item : mAuthorProd){
        orderMap[item.first].insert(item.second);
    }

    for(const auto &p : orderMap){
        cout << p.first << " :" <<endl;
        for(const auto &pp : p.second){
                cout << pp << endl;
        }
        cout << endl;
    }

    return 0;
}
