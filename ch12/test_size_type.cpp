#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::set;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main(){
    typedef vector<int>::size_type SIZE_TYPE;
    set<SIZE_TYPE> s;
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    for_each(vec.begin(),vec.end(),[&s](const int i){s.insert(i);});
    //*
    for(auto it = s.begin();it != s.end();it++){
        cout << static_cast<unsigned>(*it) << endl;
    }//*/
    cout << endl;
    for(auto i : s)
        cout << i << endl;
    return 0;
}
