#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::istream_iterator;

int main(){
    vector<int> vec;
    istream_iterator<int> in(std::cin),ineof;
    std::ostream_iterator<int> out(cout," ");
    std::copy(in,ineof,back_inserter(vec));

    cout << "reverse cout:" << endl;
    for_each(vec.crbegin(),vec.crend(),[](const int &i){cout << i << " ";});
    cout << endl << " normal cout:" << endl;
    copy(vec.cbegin(),vec.cend(),out);
    return 0;
}
