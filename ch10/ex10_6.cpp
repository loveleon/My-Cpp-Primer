#include "common.h"

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9};

    std::fill_n(vec.begin(),vec.size(),0);
    for(const auto &item :vec){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}

