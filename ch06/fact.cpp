//
// Created by cxh on 18-1-1.
//
#include "chapter/chapter6.h"
int fact(int num){
    int s = 1;
    while(num > 1){
        s *= num--;
    }
    return s;
}
