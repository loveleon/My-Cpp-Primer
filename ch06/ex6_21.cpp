#include "comm/comm.h"
int compare(int a,int* b){
    return a > *b ? a:*b;
}

int main(void){
    int a = 2 ;
    int b = 3;
    cout << "bigger one is " << compare(a,&b) << endl;

    return 0;
}
