#include "quote.h"
#include "limit_quote.h"
#include "bulk_quote.h"
#include "disc_quote.h"
#include <vector>
#include <memory>
using std::shared_ptr;

void print_debug(Quote &q)
{
    q.debug();
}

int main(){
    //std::vector<Quote&> vec;
    std::vector<Quote> vec;
    //智能指针存放Quote类型，可以调用继承类虚函数即Bulk_quote::net_price
    std::vector<shared_ptr<Quote>> pvec;

    Bulk_quote bq1("c",20.50,10,0.8);
    Bulk_quote bq2("c",20.50,10,0.8);
    Bulk_quote bq3("c",20.50,10,0.8);
    vec.push_back(bq1);
    vec.push_back(bq2);
    vec.push_back(bq3);

    auto bq4 = std::make_shared<Bulk_quote>("c",20.50,10,0.8);
    auto bq5 = std::make_shared<Bulk_quote>("c",20.50,10,0.8);
    auto bq6 = std::make_shared<Bulk_quote>("c",20.50,10,0.8);
    /*
    auto bq4 = std::make_shared<Bulk_quote>(Bulk_quote("c",20.50,10,0.8));
    auto bq5 = std::make_shared<Bulk_quote>(Bulk_quote("c",20.50,10,0.8));
    auto bq6 = std::make_shared<Bulk_quote>(Bulk_quote("c",20.50,10,0.8));
    */
    pvec.push_back(bq4);
    pvec.push_back(bq5);
    pvec.push_back(bq6);


    auto sum = 0.0f;
    for(auto bq : vec)
    {
        sum +=bq.net_price(20);
    }
    std::cout << "Quote sum :" << sum << std::endl;

    sum = 0.0f;
    for(auto pbq : pvec)
    {
        sum +=(*pbq).net_price(20);
    }
    std::cout << "Bulk_quote sum :" << sum << std::endl;
    return 0;

}
