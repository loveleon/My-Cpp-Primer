#include "quote.h"
#include <set>
#include <memory>
using std::shared_ptr;
class Basket{
    public:
        Basket() = default;
    public:
        void add_item(const Quote &sale)
        {
            item.insert(std::shared_ptr<Quote>(sale.clone()));
        }

        void add_item(Quote&& sale)
        {
            item.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
        }
        double total_receipt(std::ostream& os)const;
    private:
        static bool compare(const std::shared_ptr<Quote> &lft,const std::shared_ptr<Quote>& rhs)
        {
            return lft->isbn() < rhs->isbn();
        }
        std::multiset<std::shared_ptr<Quote>,decltype(compare)*> item{compare};
};
