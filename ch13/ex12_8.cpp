#include "ex12_8.h"

int main(){
    HasPtr has("1234");
    HasPtr has2 = has;
    HasPtr has3("23456");
    has3.print();
    has3 = has2;
    has3.print();

    return 0;
}
