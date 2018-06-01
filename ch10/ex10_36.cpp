#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using std::list;
using std::istream_iterator;
using std::ostream_iterator;
using std::cout;
using std::cin;
using std::endl;

int main(){
    istream_iterator<int> in(cin),ineof;
    ostream_iterator<int> out(cout," ");
    list<int> lst;
    copy(in,ineof,back_inserter(lst));
    auto it = find(lst.crbegin(),lst.crend(),0);
    cout << *it << endl;
    cout << *(++it) << endl;
    return 0;
}
