#pragma once
#include "disc_quote.h"
class Bulk_quote : public Disc_quote{
    public:
        Bulk_quote() = default;
        Bulk_quote(const std::string _bookNO,double _price, std::size_t _qty, double _discount):Disc_quote(_bookNO,_price, _qty, _discount){}
        virtual double net_price(std::size_t n)const override;
        virtual void debug()const override;
};
