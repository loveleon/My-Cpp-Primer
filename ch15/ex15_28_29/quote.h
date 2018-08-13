#pragma once
#include <string>
#include <iostream>

class Quote;
bool operator!=(const Quote& lft,const Quote& rhs);
class Quote{
    public:
        friend bool operator!=(const Quote& lft,const Quote& rhs);
    public:
        Quote() {std::cout <<__func__ << " default constructor."<< std::endl; }
        Quote(const std::string _bookNO,double _price):bookNO(_bookNO),price(_price){std::cout << __func__<< " normal constructor ."<<std::endl;}
        Quote(const Quote& q){bookNO = q.bookNO;price = q.price;std::cout <<__func__<< " copy constructor."<<std::endl;}
        Quote& operator=(const Quote &q){
            if(*this != q)
            {
                this->bookNO = q.bookNO;
                this->price = q.price;
            }
            std::cout << __func__<< " copy assignment ." << std::endl;
            return *this;
        };
        Quote(Quote&& q)noexcept :bookNO(std::move(q.bookNO)),price(std::move(q.price))
        {
            std::cout << __func__ << " move copy constructor." << std::endl;
        }
        Quote& operator=(Quote&& q)noexcept
        {
            if(*this != q)
            {
                bookNO = std::move(q.bookNO);
                price = std::move(q.price);
            }
            std::cout << __func__ << " move copy assignment ." << std::endl;
            return *this;
        }
        virtual double net_price(std::size_t n)const{return n * price;};
        virtual void debug()const;
        virtual ~Quote()
        {
            std::cout << __func__ << " ~Quote destructor." << std::endl;
        }
        std::string isbn()const {return bookNO;}
    private:
        std::string bookNO;
    protected:
        double price = 0.0;
};

inline bool operator!=(const Quote& lft,const Quote& rhs)
{
    return (lft.bookNO == rhs.bookNO && lft.price == rhs.price);
}
