#include "limit_quote.h"
double Limit_quote::net_price(std::size_t n)const
{
    return n * price * (n < quantity ? 1 - discount : 1);
}

void Limit_quote::debug()const {
    Quote::debug();
    std::cout << "quantity :" << quantity << " ";
    std::cout << "discount :" << discount << std::endl;
}
