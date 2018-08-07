#pragma once
#include <string>
#include <iostream>

class Quote{
    public:
        Quote() = default;
        Quote(const std::string& _bookNO,double sales_price):bookNO(_bookNO),price(sales_price){}
        std::string isbn()const {return bookNO;}
        virtual double net_price(size_t n)const{
            std::cout << "Quote net_price method get called." << std::endl;
            return n*price;}
        virtual ~Quote() = default;
    private:
        std::string bookNO;
    protected:
        double price = 0.0;
};
