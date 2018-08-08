#pragma once
#include "quote.h"
class Disc_quote :public Quote{
    public:
        Disc_quote() = default;
        Disc_quote(const std::string _bookNO,double _price,std::size_t _qty,double _discount):Quote(_bookNO,_price),quantity(_qty),discount(_discount){}
        virtual double net_price(std::size_t n)const override  = 0;
//        virtual void debug()const override {Quote::debug();}
    protected:
        std::size_t quantity = 0;
        double discount = 0.0;
};


