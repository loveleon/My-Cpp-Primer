#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

int main(){
    std::istream_iterator<int> in(cin),ineof;
    std::ostream_iterator<int> out(cout," ");
    vector<int> vec;
//    std::copy(in,ineof,back_inserter(vec));
    std::unique_copy(in,ineof,back_inserter(vec));
    std::copy(vec.cbegin(),vec.cend(),out);
    return 0;
}
