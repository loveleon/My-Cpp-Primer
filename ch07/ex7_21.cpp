#ifndef _EX7_20_H__
#define _EX7_20_H__
#include <string>
#include <iostream>

class Sales_data{
    friend std::ostream& print(std::ostream& out,Sales_data& sd);
    friend std::istream& read(std::istream& in,Sales_data& sd);
    public:
        Sales_data() = default;
        Sales_data(const std::string& bookNo_):bookNo(bookNo_){}
        Sales_data(std::istream& in);
        Sales_data(const std::string& bookNo_,unsigned units_sold_,double price):bookNo(bookNo_),units_sold(units_sold_),revenue(price*units_sold_){}

        std::string isbn()const{
            return bookNo;
        }

        Sales_data& combine(const Sales_data& rh);
    private:
            std::string bookNo;
            unsigned units_sold = 0;
            double revenue = 0.0;
};

std::ostream& print(std::ostream& out,Sales_data& sd);
std::istream& read(std::istream& in, Sales_data& sd);

Sales_data::Sales_data(std::istream& in){
    in >> bookNo >> units_sold >> revenue ;
}

Sales_data& Sales_data::combine(const Sales_data& rh){
    units_sold += rh.units_sold;
    revenue += rh.revenue;
    return *this;
}
#endif
