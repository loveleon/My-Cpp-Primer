#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::placeholders::_1;
using std::string;

int main(){

    vector<int> ivec = {1,11,111,1111,11111,111111};
    auto count = std::count_if(ivec.cbegin(),ivec.cend(),std::bind(std::greater_equal<int>(),_1,1024));
    std::cout << count << std::endl;

    vector<string> svec = {"pooh","cxh","hello","world"};
    auto pos = std::find_if(svec.cbegin(),svec.cend(),std::bind(std::not_equal_to<string>(),_1,"pooh"));
    std::cout << *pos << std::endl;

    std::transform(ivec.cbegin(),ivec.cend(),ivec.begin(),std::bind(std::multiplies<int>(),_1,2));
    for(auto i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
