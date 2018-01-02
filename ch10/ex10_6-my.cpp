#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(){
    vector<int> v = {0,1,2,3,4,5,6,7,8,9,10,11};
    std::fill_n(v.begin(),v.size(),0);
    for(auto &i : v)
        cout << i << " ";
    cout << endl;
    return 0;
}
