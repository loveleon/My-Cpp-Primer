#include "common.h"

int main(){
    multimap<string,string> mAutorPro;
    string autor,product;
    while(cin >> autor >> product){
//        mAutorPro.emplace({autor,product});
        mAutorPro.emplace(autor,product);
    }
    cin.clear();

    cout << "input delete autor name:" << endl;
    string nm;
    cin >> nm;
    auto pos = mAutorPro.find(nm);
    if(pos != mAutorPro.end()){
        mAutorPro.erase(pos);
    }else{
        cout << "autor " << nm << " isn't in the map" << endl;
    }

    for(const auto &M :mAutorPro){
        cout << M.first << " :"<< M.second<<endl;
    }

    return 0;
}
