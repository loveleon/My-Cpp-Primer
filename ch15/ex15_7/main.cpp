#include <iostream>
#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

double print_total(std::ostream& out, const Quote& q,size_t n);

int main()
{
    Quote q("c++",10.60);
    Bulk_quote bq("c++",10.60,10,0.3);
    Limit_quote lq("c",10.60,10,0.3);

    print_total(std::cout,q,5);
    print_total(std::cout,bq,5);
    print_total(std::cout,lq,5);
}

double print_total(std::ostream& out, const Quote& q, size_t n)
{
    double ret = q.net_price(n);
    out << "isbn:" << q.isbn() << " sold number:" << n
        << " total money:" << ret << std::endl;
    return ret;
}
