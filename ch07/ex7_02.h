#include "comm.h"
class Sales_data
{
    public:
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;

    public:
        Sales_data& combine(Sales_data& rh);
        string isbn() const;
};

Sales_data& Sales_data::combine(Sales_data& rh){

    units_sold += rh.units_sold;
    revenue += rh.revenue;
    return *this;
}

string Sales_data::isbn() const{
    return bookNo;
}

