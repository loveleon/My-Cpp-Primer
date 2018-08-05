#include "ex14_45.h"

Sales_data::Sales_data(std::istream& is):Sales_data()
{
    is >> *this;
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    revenue += rhs.revenue;
    units_sold += rhs.units_sold;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Sales_data& sd)
{
    out << sd.isbn() << " " << sd.units_sold << " " << sd.revenue << " " << sd.avg_price();
    return out;
}

std::istream& operator>>(std::istream& in, Sales_data& sd)
{
    double price = 0.0f;
    in >> sd.bookNo >> sd.units_sold >> price;
    if(in)
        sd.revenue = price * sd.units_sold;
    else{
        sd = Sales_data();
    }

    return in;
}

Sales_data operator+(const Sales_data& lft,const Sales_data& rhs)
{
    Sales_data tmp = lft;
    tmp += rhs;
    return tmp;
}

Sales_data& Sales_data::operator=(const std::string& str)
{
    *this = Sales_data(str);
    return *this;
}
