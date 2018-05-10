//
// Created by cxh on 18-5-10.
//

#ifndef CH06_EX7_52_H
#define CH06_EX7_52_H
#include <string>
#include <iostream>

struct Sales_data{
    std::string bookNo;
    unsigned units_sold ;//= 0; //drop in-class initializer
    double revenue ;//= 0.0;   //drop in-class initializer
};

int main(){
    Sales_data item = {"978-0590353403",25,15.99};
    std::cout << item.bookNo << " " << item.revenue << " " << item.units_sold << std::endl;

    return 0;
}
#endif //CH06_EX7_52_H
