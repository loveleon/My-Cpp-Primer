#pragma once
#include "quote.h"
class Bulk_quote: public Quote {
    public:
        Bulk_quote() = default;
        Bulk_quote(const std::string& _bookNO,double _price, std::size_t _min_qty, double _discount):
            Quote(_bookNO,_price),min_qty(_min_qty),discount(_discount){}
        virtual double net_price(std::size_t )const override;
        virtual void Debug() override {
            Quote::Debug();
            std::cout << "min_qty:" << this->min_qty<< " "
                << "discount:" << this->discount<< std::endl;;
        }
    private:
        std::size_t min_qty = 0;
        double discount = 0.0;
};
