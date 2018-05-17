#include "common.h"
struct Sales_data{
    friend bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs);
    string bookNo;
    string name;
    string isbn()const {return bookNo;}
};

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}

int main(){
    multiset<Sales_data,bool (*)(const Sales_data &,const Sales_data &)> bookstore(compareIsbn);
    Sales_data sd = {"zzz-yyy-xxx","c++"};
    Sales_data sd1 = {"www-yyy-xxx","c"};
    Sales_data sd2 = {"hhh-yyy-xxx","python"};
    Sales_data sd3 = {"hhh-xyy-xxx","golang"};
    bookstore.insert(sd);
    bookstore.insert(sd1);
    bookstore.insert(sd2);
    bookstore.insert(sd3);

    for(auto s : bookstore){
        cout << s.bookNo << " " << s.name << endl;
    }

    return 0;
}
