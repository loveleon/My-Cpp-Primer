//#pragma once
#ifndef _EX14_7_H
#define _EX14_7_H
#include <string>
#include <iostream>

class Sales_data{
    public:
        friend std::istream& operator>>(std::istream &in, Sales_data &sd);
        friend std::ostream& operator<<(std::ostream &out,const Sales_data &sd);
        friend Sales_data operator+(const Sales_data &lft,const Sales_data &rhs);
        friend Sales_data operator-(const Sales_data &lft,const Sales_data &rhs);
    public:
        Sales_data(const std::string &s,unsigned int n, double p):bookNo(s),units_sold(n),revenue(n*p){
            std::cout << "Sales_data:" << std::endl;
            std::cout << bookNo << " " << units_sold << " " << revenue << std::endl;
        }
        Sales_data():Sales_data("",0,0.0f){}
        //Sales_data(const std::string &s):bookNo(s),units_sold(0),revenue(0.0){}
        Sales_data(const std::string &s):Sales_data(s,0,0.0f){}
        Sales_data(std::istream &is);

        Sales_data& operator+=(const Sales_data &rhs);
        Sales_data& operator-=(const Sales_data &rhs);
        std::string isbn()const{return bookNo;}
    private:
        inline double avg_price()const;
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};
    std::istream& operator>>(std::ostream &in, Sales_data &sd);//cin
    std::ostream& operator<<(std::ostream &out,const Sales_data &sd);//cout
    Sales_data operator+(const Sales_data &lft,const Sales_data &rhs);

    inline double Sales_data::avg_price() const {
        return units_sold ? revenue/units_sold:0;
    }
#endif
