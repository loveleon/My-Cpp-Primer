#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;
using std::cin;
using std::cout;

int main(){
    std::istream_iterator<int> in(cin),ineof;
    std::ostream_iterator<int> out(cout," ");
    vector<int> vec;
    copy(in,ineof,back_inserter(vec));
    std::sort(vec.begin(),vec.end());
    copy(vec.cbegin(),vec.cend(),out);
    return 0;
}
