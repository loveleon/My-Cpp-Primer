#include "ex7_15.h"
int main(){
    Person p;
    print(std::cout,p) << std::endl;

    Person p1("cxh","xxx.www.yy");
    print(std::cout,p1) << std::endl;

    Person p2;
    read(std::cin,p2);
    print(std::cout,p2) << std::endl;
    return 0;
}
