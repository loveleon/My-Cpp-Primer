#ifndef _ex8_06_h__
#define _ex8_06_h__
#include <string>
#include <iostream>
#include <fstream>
using std::istream;
using std::ostream;
using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::ifstream;

struct Sales_data{
    string bookNo;
    unsigned units_sold;
    double revenue;
   friend istream& read(istream& inFile,Sales_data& sd);
    string isbn(){return bookNo;}
    void combine(const Sales_data& sd);
   friend ostream& print(ostream& out,const Sales_data& sd);
};

istream& read(istream& in,Sales_data& sd);
ostream& print(ostream& out,const Sales_data& sd);

void Sales_data::combine(const Sales_data& sd){
    units_sold += sd.units_sold;
    revenue +=sd.revenue;
}

ostream& print(ostream& out, const Sales_data& sd){
    out << sd.bookNo << " " << sd.units_sold << " " << sd.revenue;
    return out;
}

istream& read(istream& in,Sales_data& sd){
    in >> sd.bookNo >> sd.units_sold >> sd.revenue;
    return in;
}
#endif
