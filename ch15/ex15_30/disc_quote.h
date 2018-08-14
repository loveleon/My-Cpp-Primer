#pragma once
#include "quote.h"
class Disc_quote :public Quote{
    public:
        Disc_quote() {
//            std::cout << __func__ << " default constructor." << std::endl;
        }

        Disc_quote(const std::string _bookNO,double _price,std::size_t _qty,double _discount):Quote(_bookNO,_price),quantity(_qty),discount(_discount)
        {
 //           std::cout << __func__ << " normal constructor." << std::endl;
        }

        //copy constructor.
        Disc_quote(const Disc_quote& dq):Quote(dq),quantity(dq.quantity),discount(dq.discount)
        {
  //          std::cout << __func__ << " copy constructor." << std::endl;
        }

        //copy assignment
        Disc_quote& operator=(Disc_quote& dq)
        {
            if(*this != dq)
            {
                Quote::operator=(dq);
                quantity = dq.quantity;
                discount = dq.discount;
            }
            return *this;
        }

        //move constructor
        Disc_quote(Disc_quote&& bq)noexcept:Quote(std::move(bq)),quantity(std::move(bq.quantity)),discount(std::move(bq.discount))
        {
   //         std::cout <<__func__ << " move constructor." << std::endl;
        }

        //move assignment constructor.
        Disc_quote& operator=(Disc_quote&& bq)noexcept
        {
            if(*this != bq)
            {
                Quote::operator=(std::move(bq));
                quantity = std::move(bq.quantity);
                discount = std::move(bq.discount);
            }
            return *this;
        }

        ~Disc_quote()
        {
    //        std::cout << __func__ << " ~Disc_quote destructor." << std::endl;
        }

        virtual double net_price(std::size_t n)const override  = 0;
//        virtual void debug()const override {Quote::debug();}
    protected:
        std::size_t quantity = 0;
        double discount = 0.0;
};


