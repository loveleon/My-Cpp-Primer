#include "quote.h"
void Quote::debug()const {
    std::cout << "this class member : ";
    std::cout << "bookNO : " << bookNO << " ";
    std::cout << "price : " << price << " ";
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    // depending on the type of the object bound to the item parameter
    // calls either Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // calls Quote::isbn
       << " # sold: " << n << " total due: " << ret << std::endl;
     return ret;
}
