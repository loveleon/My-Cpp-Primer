#include "ex13_21_Test.h"

int main(){
    std::ifstream infile("../ex13_21_Test.h",infile.in);
    TextQuery q(infile);
    std::string msg;
    while(std::cin >> msg){
        if(!std::cin || msg == std::string("q"))
            break;
        auto qr = q.query(msg);
        print(std::cout, qr) << std::endl;
    }

    return 0;
}
