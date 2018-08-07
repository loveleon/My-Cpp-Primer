#pragma once
#include "quote.h"
class Limit_quote: public Quote {
    public:
        Limit_quote() = default;
        Limit_quote(const std::string& _bookNO,double _price, std::size_t _max_qty, double _discount):
            Quote(_bookNO,_price),max_qty(_max_qty),discount(_discount){}
        virtual double net_price(std::size_t )const override;
        virtual void Debug() override final {
            Quote::Debug();
            std::cout << "max_qty:" << this->max_qty << " "
                <<"discount:" << this->discount<< std::endl;
        }
    private:
        std::size_t max_qty = 0;
        double discount = 0.0;
};
