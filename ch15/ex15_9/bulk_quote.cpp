#include "bulk_quote.h"
double Bulk_quote::net_price(std::size_t n)const
{
    std::cout << "Bulk_quote net_price method get called." << std::endl;
    return n*price*(n>= min_qty ? 1-discount : 1);
}
