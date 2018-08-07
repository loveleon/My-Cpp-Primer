#include <iostream>
#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

double print_total(std::ostream& out, const Quote& q,size_t n);
void print_debug(Quote& q);

int main()
{
    Quote q("aaa",10.60);
    Bulk_quote bq("bbb",111,10,0.3);
    Limit_quote lq("ccc",222,10,0.3);

    Quote& r = q;
    r.Debug();

    r=bq;
    r.Debug();

    r = lq;
    r.Debug();

    std::cout << "========================" << std::endl;
    print_debug(q);
    print_debug(bq);
    print_debug(lq);

    return 0;
}

double print_total(std::ostream& out, const Quote& q, size_t n)
{
    double ret = q.net_price(n);
    out << "isbn:" << q.isbn() << " sold number:" << n
        << " total money:" << ret << std::endl;
    return ret;
}

void print_debug(Quote& q)
{
    q.Debug();
}
