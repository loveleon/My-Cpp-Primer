#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <algorithm>

using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    list<int> lst;
    list<int> lst_r(6-2);
    copy(vec.cbegin()+2,vec.cbegin()+6,lst_r.rbegin());
    for_each(lst_r.cbegin(),lst_r.cend(),[](const int &i){cout << i << " ";});
    cout << endl;
    copy(vec.cbegin()+2,vec.cbegin()+6,front_inserter(lst));
    for_each(lst.begin(),lst.end(),[](const int &i){cout << i << " ";});
    cout << endl;
    return 0;
}
