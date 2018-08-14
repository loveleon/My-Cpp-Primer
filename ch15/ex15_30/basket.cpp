#include "basket.h"

double Basket::total_receipt(std::ostream& os)const
{
    double sum = 0.0f;
    for(auto iter = item.cbegin();iter != item.cend();iter = item.upper_bound(*iter))
    {
        sum += print_total(os,**iter,item.count(*iter));
    }
    os << "Total slaes: " << sum << std::endl;
    return sum;
}
