#include "ex14_45.h"

int main(){
    Sales_data sd("c+++",4,100.0);
    std::cout << sd << std::endl;
    std::cout << static_cast<std::string>(sd) << std::endl;
    std::cout << static_cast<double>(sd) << std::endl;
    return 0;
}
