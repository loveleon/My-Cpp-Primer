#pragma once
#include <string>
#include <iostream>

class Sales_data{
    friend std::ostream& operator<<(std::ostream& out, const Sales_data&);
    friend std::istream& operator>>(std::istream& is, Sales_data &);
    friend void print(const Sales_data&);
    friend Sales_data operator+(const Sales_data&,const Sales_data&);
    public:
        Sales_data(const std::string& _bookNo,unsigned _units_sold,double _price):bookNo(_bookNo),units_sold(_units_sold),revenue(_price*_units_sold){}
        Sales_data():Sales_data("",0,0.0f){}
        Sales_data(const std::string& str):Sales_data(str,0,0.0f){}
        Sales_data(std::istream& is);

        Sales_data& operator=(const std::string& str);
        Sales_data& operator+=(const Sales_data& sd);
        explicit operator std::string() const{return bookNo;}
        explicit operator double() const{return avg_price();}

        std::string isbn()const {return bookNo;}
    private:
        inline double avg_price()const;
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
};
std::ostream& operator<<(std::ostream& out, const Sales_data&);
std::istream& operator>>(std::istream& is, Sales_data &);
void print(const Sales_data&);
Sales_data operator+(const Sales_data&,const Sales_data&);

inline double Sales_data::avg_price()const
{
    return units_sold?revenue/units_sold:0;
}
