//
// Created by cxh on 18-5-10.
//

#ifndef MY_CPP_PRIMER_EX7_57_H
#define MY_CPP_PRIMER_EX7_57_H
#include <string>
#include <iostream>
using std::string;

class Account{
public:
    static  double rate();
    static  void rate(double);
public:
    static double interestRate;
private:
    std::string owner;
    static double initRate();
    //static  double interestRate;
    double  amount = 20.0;
    constexpr static double init_rate = 3.3;
    constexpr static int global = 40;
    static constexpr int  period = 30;
    double daily_tbl[period];
};
#endif //MY_CPP_PRIMER_EX7_57_H
