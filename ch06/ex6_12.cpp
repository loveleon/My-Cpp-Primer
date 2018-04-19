#include "comm/comm.h"

void swap(int &a,int &b){
    int tmp;
    tmp = a;
    a   = b;
    b   = tmp;
}

int main(void){
    int a= 5,b=2;
    swap(a,b);
    cout << "after swap ,a "<< a << ",b " << b <<endl;

    return 0;
}
