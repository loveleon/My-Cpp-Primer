#ifndef _EX7_41_H__
#define _EX7_41_H__

#include <iostream>
#include <string>
using std::string;

class Sales_data;
std::istream& read(std::istream& is, Sales_data& sd);

class Sales_data{
    private:
    public:
        string bookNo;
        double revenue;
        unsigned units_sold;
    public:
        Sales_data(string bookNo_,double price, unsigned us):bookNo(bookNo_),revenue(price*us),units_sold(us){std::cout << "委托构造函数调用"<<std::endl;}
        Sales_data():Sales_data("",0.0,0){std::cout << "默认构造函数调用" <<std::endl;}
        Sales_data(string bookNo_):Sales_data(bookNo_,0.0,0){std::cout << "单参数构造函数调用"<<std::endl;}
        Sales_data(std::istream& is):Sales_data("",0.0,0){
            read(is,*this);
            std::cout << "输入流版构造函数调用" << std::endl;
        }
};

std::istream& read(std::istream& is, Sales_data& sd){
    double price;
    is >> sd.bookNo >> price >> sd.units_sold;
    sd.revenue = price * sd.units_sold;
    return is;
}
#endif
