//
// Created by cxh on 18-1-1.
//

#include "comm/comm.h"
void swap(int *a,int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a=5,b=2;
    swap(&a,&b);
    cout << "after swap a:"<< a << ",b:"<<b<<endl;
    return 0;
}