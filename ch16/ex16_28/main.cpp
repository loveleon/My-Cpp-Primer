#include <iostream>
#include <vector>
#include "shared_pointer.hpp"
#include "unique_pointer.h"
#include "delete.hpp"

int main()
{
    auto foo = cp5::SharedPointer<int>(new int(5));
    auto var(foo);
    auto foof = cp5::SharedPointer<int>(new int(10));
    //std::cout << *foo << std::endl;
    //std::cout <<foo.use_count() << std::endl;
    //foof.swap(foo);
    //std::cout << "after swap ," << *foof << std::endl;

    auto foostr = cp5::SharedPointer<std::string>(new std::string("xxxx"));
    //std::cout << *foostr << std::endl;
    //std::cout << foostr->size() << std::endl;

    auto foou = unique_pointer<int>(new int(5));
    auto foop = unique_pointer<int>(new int(10));
    std::cout << *foop << std::endl;
    foop = std::move(foou);
    //foou.swap(foop);
    std::cout << *foop << std::endl;
    return 0;
}

