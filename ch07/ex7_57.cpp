//
// Created by cxh on 18-5-10.
//
#include "ex7_57.h"

constexpr int Account::global ;

double Account::initRate(){
    return init_rate;
}
double Account::interestRate = initRate();

double Account::rate() {
    return interestRate;
}

void Account::rate(double d){
    interestRate = d;
}
