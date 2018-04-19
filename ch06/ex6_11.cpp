//
// Created by cxh on 18-4-18.
//
#include "comm/comm.h"

void reset(int &num){
    num = 0;
}

int main(){
    int a = 100;
    reset(a);
    cout << " reset a " << a << endl;
}