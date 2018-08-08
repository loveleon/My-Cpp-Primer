#include "quote.h"
#include "limit_quote.h"
#include "bulk_quote.h"
#include "disc_quote.h"

void print_debug(Quote &q)
{
    q.debug();
}

int main(){
    Limit_quote lq("cpp",50.50,100,0.5);
    Bulk_quote bq("c",20.50,20,0.8);

    std::cout << "net price :" << lq.net_price(110) ;
    std::cout << "net price :" << bq.net_price(10);

    print_debug(lq);
    print_debug(bq);

    return 0;
}
