#include "ex13_58.h"

int main(){
    //*
    Foo f = {9,8,7,6,5,7,5,4,3,2,1};
    std::cout << "left value version will be called?" << std::endl;
    auto ret_lvlue = f.sorted();
    print(std::cout,ret_lvlue) << std::endl;

    Foo f2 = {19,17,15,13,3,1};
    std::cout << "right value version will be called?" << std::endl;
    auto ret_rvlue = std::move(f2).sorted();
    print(std::cout,std::move(ret_rvlue)) << std::endl;
    //*/
    /*
    Foo().sorted();

    Foo f;
    f.sorted();
    */
    return 0;
}
