#include <iostream>
#include <vector>

#include "vec.h"

int main(){
    Vec<int> v1 = {1,2,3,4,5,6};
    Vec<int> v2;
    v2 = v1;
    std::cout << v2.capacity() << std::endl;
    v2.push_back(99);
    v2.resize(2,2);

    for(auto it : v2)
        std::cout << it << "\t";
    std::cout << v2.capacity() << std::endl;

    return 0;
}
