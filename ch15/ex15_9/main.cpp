#include <iostream>
#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

double print_total(std::ostream& out, const Quote& q,size_t n);

int main()
{
    Bulk_quote bq("c++",10.60,10,0.3);

    Quote* q = &bq;
    q->net_price(5);

    Quote& qq = bq;
    qq.net_price(5);

    Quote qqq = bq;
    qqq.net_price(5);

    return 0;
}

double print_total(std::ostream& out, const Quote& q, size_t n)
{
    double ret = q.net_price(n);
    out << "isbn:" << q.isbn() << " sold number:" << n
        << " total money:" << ret << std::endl;
    return ret;
}
