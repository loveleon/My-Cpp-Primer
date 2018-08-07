#include <iostream>
#include "quote.h"
double print_total(std::ostream& out, const Quote& q,size_t n);

int main()
{
    Quote q("c++",100);
    std::cout << print_total(std::cout,q,100);
}

double print_total(std::ostream& out, const Quote& q, size_t n)
{
    double ret = q.net_price(n);
    out << "isbn:" << q.isbn() << " sold number:" << n
        << " total money:" << ret << std::endl;
    return ret;
}
