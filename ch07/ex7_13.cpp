#include "ex7_12.h"

int main(){
    Sales_data total(std::cin);
    if(!total.isbn().empty()){
        std::istream& is(std::cin);
        while(is){
            Sales_data trans(is);
            if(total.isbn() == trans.isbn()){
                total.combine(trans);
//                print(std::cout,total);
            }else{
                print(std::cout,total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total);
    }
    else{
        std::cerr << "no input data." << std::endl;
    }

    return 0;
}

