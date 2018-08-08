#pragma once
#include <string>
#include <iostream>

class Quote{
    public:
        Quote() = default;
        Quote(const std::string _bookNO,double _price):bookNO(_bookNO),price(_price){}
        virtual double net_price(std::size_t n)const{return n * price;};
        virtual void debug()const;
        virtual ~Quote() = default;
        std::string isbn()const {return bookNO;}
    private:
        std::string bookNO;
    protected:
        double price = 0.0;
};
