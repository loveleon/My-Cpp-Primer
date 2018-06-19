#include "ex13_22.h"

int main(){
    HasPtr has;
    HasPtr has2 = has;
    HasPtr has3("123",3);
    print(std::cout,has)<< std::endl;
    print(std::cout,has2)<< std::endl;
    print(std::cout,has3)<< std::endl;

    return 0;
}
