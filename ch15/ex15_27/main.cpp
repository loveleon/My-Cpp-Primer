#include "quote.h"
#include "limit_quote.h"
#include "bulk_quote.h"
#include "disc_quote.h"

void print_debug(Quote &q)
{
    q.debug();
}

int main(){
    Bulk_quote bq1;
    Bulk_quote bq("c",20.50,20,0.8);
    bq1  = std::move(bq);

    return 0;
}
