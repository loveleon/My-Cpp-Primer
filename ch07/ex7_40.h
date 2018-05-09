#ifndef _EX7_40_H__
#define _EX7_40_H__
#include <string>
#include <iostream>
using std::string;

class Book{
    public:
        Book() = default;
        Book(string bookNm_, double price_, string sn_):bookNm(bookNm_),price(price_),sn(sn_){}
        Book(std::istream& is);
        double get_price() const {return price;}
        void set_price(double price_){price = price_;}
        string get_sn()const{return sn;}
    private:
        string bookNm;
        double price;
        string sn;
};

Book::Book(std::istream& is){
         is >> bookNm >> price >> sn;
     }
#endif
