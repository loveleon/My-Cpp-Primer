#include "ex13_53.h"

int main(){
    HasPtr hp1("nihao"),hp2("shenzhen"),*pH = new HasPtr("guangdong");
    hp1 = hp2;
    hp1 = std::move(*pH);
    return 0;
}
