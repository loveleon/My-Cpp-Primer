
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

Sales_data add(Sales_data& lf, Sales_data& rt){
    Sales_data sum = lf;
    sum.combine(rt);
    return sum;
}

std::istream& read(std::istream& os, Sales_data& in){
    os >> in.bookNo >> in.units_sold >> in.revenue;
    return os;
}

std::ostream& print(std::ostream& os, const Sales_data& out){
    os << out.bookNo << " " << out.units_sold << " " << out.revenue;
    return os;
}
