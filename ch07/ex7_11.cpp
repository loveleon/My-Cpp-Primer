
#include "comm.h"
#include <cstdlib>
#include <cstdio>
class Sales_data
{
    public:
        Sales_data(istream& os);
        Sales_data(const string& bookNo_):bookNo(bookNo_){cout << __func__ <<"(string) is called." << endl;}
        Sales_data(const string& bookNo_, unsigned units_sold_,double price):
            bookNo(bookNo_),units_sold(units_sold_),revenue(price*units_sold_)
        {
            cout << __func__ << "(string,usigned,double) is called." << endl;
        }
        Sales_data() = default;
    public:
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;

    public:
        Sales_data& combine(Sales_data& rh);
        string isbn() const;
};

extern std::istream& read(istream& os, Sales_data& sd);

Sales_data::Sales_data(istream& os){
    read(os,*this);
    cout << __func__ << "(istream&) is called." <<endl;
}

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

int main(){
    string str = string("123");
    Sales_data deaultS;
    Sales_data s2("111");
    Sales_data s3(str,1,1.1);
    Sales_data s4(cin);

    return 0;
}
