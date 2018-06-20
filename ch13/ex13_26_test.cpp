#include "ex13_26.h"

int main(){
    ifstream file("../ex13_26.h",file.in);
    StrBlob sb1(file);
    StrBlob sb2 = sb1;
    print(std::cout,sb1) << std::endl;
    return 0;

}
