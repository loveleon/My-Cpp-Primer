#include "ex14_2.h"

Sales_data::Sales_data(std::istream &is):Sales_data(){
    is >> *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs){
    revenue += rhs.revenue;
    units_sold += rhs.units_sold;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Sales_data &sd){
    out << sd.isbn() <<" " << sd.units_sold <<" " << sd.revenue;
    return out;
}
//*
std::istream& operator>>(std::istream &is, Sales_data &sd){
    double price = 0.0;
    is >> sd.bookNo >> sd.units_sold >> price;
    std::cout << __func__ << " price:" << price << std::endl;
    sd.revenue = sd.units_sold * price;
   // if(is){
   //    sd.revenue = sd.units_sold * price;
   // }else{
   //     sd = Sales_data();
   // }
    return is;
}
//*/

Sales_data operator+(const Sales_data &lft,const Sales_data &rhs){
    Sales_data tmp = lft;
    tmp.revenue += rhs.revenue;
    tmp.units_sold += rhs.units_sold;
    return tmp;
}


