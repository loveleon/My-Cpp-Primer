#include "quote.h"
#include "limit_quote.h"
#include "bulk_quote.h"
#include "disc_quote.h"
#include <vector>

void print_debug(Quote &q)
{
    q.debug();
}

int main(){
    //std::vector<Quote&> vec;
    std::vector<Quote> vec;
    Bulk_quote bq1("c",20.50,20,0.8);
    Bulk_quote bq2("c",20.50,20,0.8);
    Bulk_quote bq3("c",20.50,20,0.8);

    vec.push_back(bq1);
    vec.push_back(bq2);
    vec.push_back(bq3);

    auto sum = 0.0f;
    for(auto bq : vec)
    {
        sum +=bq.net_price(20);
    }
    std::cout << "sum :" << sum << std::endl;
    return 0;

}
