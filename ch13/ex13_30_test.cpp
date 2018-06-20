#include "ex13_30.h"

int main(){
    HasPtr has("test",4);
    print(std::cout,has)<<"this is has value" << std::endl;
    HasPtr has2("cxh",3);
    print(std::cout,has2)<<"this is has2 value" << std::endl;
    swap(has,has2);
    print(std::cout,has2)<<"this is new has2 value" << std::endl;
    //has2 = has;

    //print(std::cout,has2)<<std::endl;
    return 0;
}
