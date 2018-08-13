#pragma once
#include "disc_quote.h"
class Bulk_quote : public Disc_quote{
    public:
        Bulk_quote() {
            std::cout << __func__ << " default constructor." << std::endl;
        }
        /*
        Bulk_quote(const std::string _bookNO,double _price, std::size_t _qty, double _discount):Disc_quote(_bookNO,_price, _qty, _discount)
        {
            std::cout << __func__ << " normal constructor." << std::endl;
        }
        */
        using Disc_quote::Disc_quote;
        //copy constructor
        Bulk_quote(const Bulk_quote& bq):Disc_quote(bq){
            std::cout << __func__ << " copy constructor." << std::endl;
        }

        Bulk_quote& operator=(Bulk_quote& bq){
            if(*this != bq)
            {
                *this = bq;
            }
            std::cout << __func__ << "(Bulk_quote) copy assignment." << std::endl;
            return *this;
        }

        //move constructor
        Bulk_quote(Bulk_quote&& bq)noexcept:Disc_quote(std::move(bq))
        {
            std::cout << __func__ << " move copy constructor." << std::endl;
        }

        //move assignment constructor
        Bulk_quote& operator=(Bulk_quote&& bq)noexcept
        {
            if(*this != bq)
            {
                Disc_quote::operator=(std::move(bq));
            }
            std::cout << __func__ << "(Bulk_quote) move assignment constructor." << std::endl;
            return *this;
        }

        ~Bulk_quote()
        {
            std::cout << __func__ << " ~Bulk_quote destructor." << std::endl;
        }

        virtual double net_price(std::size_t n)const override;
        virtual void debug()const override;
};
