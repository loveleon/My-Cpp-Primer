#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
//using namespace std;
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::cin;


int main(){
    vector<int> vec;
    list<int> lst;
    int i;
    cout << "input (i) ";
    while(cin >> i){
        lst.push_back(i);
    }
    vec.resize(lst.size());
    std::copy(lst.begin(),lst.end(),vec.begin());
    for (auto i : vec)
        cout << i << " ";
    cout << endl;


    return 0;
}
