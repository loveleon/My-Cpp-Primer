//
// Created by cxh on 18-1-1.
//
#include "comm.h"
void acculate_addr(int addr){
    cout << static_cast<void *>(&addr) << endl;
}

int main(){
    int ab = 5;
    acculate_addr(ab);

    return 0;
}

