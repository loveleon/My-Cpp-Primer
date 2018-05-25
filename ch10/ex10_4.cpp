#include "common.h"

int main(){
    double tmp = 0.0;
    vector<double> vec;
    while(cin >> tmp){
        vec.push_back(tmp);
    }

    double sum = 0.0;
    sum = std::accumulate(vec.cbegin(),vec.cend(),0);
    cout << "sum:" << sum << endl;
    return 0;
}
