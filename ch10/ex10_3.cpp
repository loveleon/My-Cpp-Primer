#include "common.h"

int main(){
    vector<int> vec;
    uint32_t tmp;
    while(cin >> tmp){
        cout << tmp << endl;
        vec.push_back(static_cast<int>(tmp));
    }
    int sum= 0;
    sum = std::accumulate(vec.cbegin(),vec.cend(),sum);
    cout << "sum:" << sum << endl;
    return 0;
}
