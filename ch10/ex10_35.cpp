#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::for_each;

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    auto beg = vec.rbegin();
    auto end = vec.rend();
    for_each(beg,end,[](const int &i){cout << i << " ";});
    cout << endl;
    for(auto start_end = std::prev(vec.cend());true;--start_end ){
        if( start_end == vec.cbegin() ){
            cout << *start_end << endl;
            break;
        }else{
            cout << *start_end << " ";
        }

    }
    cout << endl;
    return 0;
}
