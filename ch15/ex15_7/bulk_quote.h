#pragma once
#include "quote.h"
class Bulk_quote: public Quote {
    public:
        Bulk_quote() = default;
        Bulk_quote(const std::string& _bookNO,double _price, std::size_t _min_qty, double _discount):
            Quote(_bookNO,_price),min_qty(_min_qty),discount(_discount){}
        virtual double net_price(std::size_t )const override;
    private:
        std::size_t min_qty = 0;
        double discount = 0.0;
};
