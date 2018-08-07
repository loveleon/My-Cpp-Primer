#include "limit_quote.h"
double Limit_quote::net_price(std::size_t n)const
{
    std::cout << "Limit_quote net_price get called." << std::endl;
    if(n > max_qty)
        return max_qty*price*discount+(n-max_qty)*price;
    else
        return n*price*discount;
}
