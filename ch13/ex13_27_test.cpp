#include "ex13_27.h"

int main(){
    HasPtr has("test");
    //HasPtr has2 = has;
    //has = has;
    //*
    HasPtr has3;
    //has3 = has2;
    has = has3;
    print(std::cout,has) << std::endl;
//    print(std::cout,has2) << std::endl;
    print(std::cout,has3) << std::endl;
    //*/
    return 0;
}
