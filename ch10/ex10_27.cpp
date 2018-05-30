#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <set>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::set;

int main(){
    vector<int> vec = {1,2,2,3,3,4,5,4,5,6,6,7,7,8,9,8,0,9,0,10};
    list<int> lst;
    set<int> s;
    std::unique_copy(vec.cbegin(),vec.cend(),std::front_inserter(lst));
    std::copy(vec.cbegin(),vec.cend(),inserter(s,s.begin()));
    cout << "list:";
    for_each(lst.cbegin(),lst.cend(),[](const int & i){cout << i << " ";});
    cout << endl;
    cout << "set:";
    for_each(s.cbegin(),s.cend(),[](const int &i){cout << i << " ";});
    cout << endl;
    return 0;
}
