#include "common.h"

int main(){
    vector<int> vec;
    int iNum;
    while(cin >> iNum){
        vec.push_back(iNum);
    }

    cin.clear();
    cout << "input a test number:" << endl;
    int iTest;
    cin >> iTest;
    auto it = std::count(vec.cbegin(),vec.cend(),iTest);
    cout << "times:" << it <<endl;
    return 0;
}
