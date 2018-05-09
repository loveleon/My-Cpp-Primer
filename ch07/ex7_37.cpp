#include "ex7_37.h"

Sales_data first_item(std::cin);
int main(){
    Sales_data next;
    Sales_data last("9-999-99999-9");

    std::cout << first_item.bookNo << " " << first_item.units_sold << " " << first_item.revenue << std::endl;
    std::cout << next.bookNo << " " << next.units_sold << " " << next.revenue << std::endl;
    std::cout << last.bookNo << " " << last.units_sold << " " << last.revenue << std::endl;
    return 0;
}

