#include "ex14_7.h"

int main(){
    Sales_data sd1("cxh",10,10.2);
    Sales_data sd2("cxh",20,9.2);
    std::cout << sd1 -sd2 << std::endl;

    return 0;
}
