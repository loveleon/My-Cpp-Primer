#ifndef _EX7_40_H__
#define _EX7_40_H__
#include <string>
#include <iostream>
using std::string;

class Book{
    public:
        Book();
        Book(string bookNm_, double price_, string sn_):bookNm(bookNm_),price(price_),sn(sn_){std::cout << "Entrusted Constructor"<<std::endl;}
        Book(std::istream& is);
        double get_price() const {return price;}
        void set_price(double price_){price = price_;}
        string get_sn()const{return sn;}
    private:
        string bookNm;
        double price;
        string sn;
};


Book::Book():Book("",0.0,""){
    std::cout << "Default Constructor" << std::endl;
}

Book::Book(std::istream& is):Book("weituo",1.1,"xx-yyyy-zz"){
        std::cout << "istream Constructor" << std::endl;
        std::cout << bookNm << price << sn <<std::endl;
         is >> bookNm >> price >> sn;
        std::cout << bookNm << price << sn <<std::endl;
     }
#endif
