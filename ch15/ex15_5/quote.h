#pragma once
#include <string>

class Quote{
    public:
        Quote() = default;
        Quote(const std::string& _bookNO,double sales_price):bookNO(_bookNO),price(sales_price){}
        std::string isbn()const {return bookNO;}
        virtual double net_price(size_t n)const{return n*price;}
        virtual ~Quote() = default;
    private:
        std::string bookNO;
    protected:
        double price = 0.0;
};
