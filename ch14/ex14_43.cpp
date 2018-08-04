#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using std::vector;
using std::placeholders::_1;

int main()
{
    vector<int> ivec = {2,4,6,8,10};
    int input ;
    std::cin >> input;
    std::modulus<int> mod;
    auto predicate = [&](int i)->bool{ return 0 == mod(input,i); };
    auto is_diviable = std::all_of(ivec.cbegin(),ivec.cend(),predicate);
    std::cout << std::boolalpha << is_diviable << std::endl;
    return 0;
}
