#include "comm/comm.h"

void swap(int*& a,int*& b){
    auto tmp = a;
    a   = b;
    b   = tmp;
}
int main(void){
    int a = 2 ;
    int b = 3;
    auto lf = &a;
    auto rt = &b;
    cout << "before:" << *lf << " " << *rt << endl;
    swap(lf,rt);
    cout << "after:" << *lf << " " << *rt <<endl;
    return 0;
}
