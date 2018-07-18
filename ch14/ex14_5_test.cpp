#include "ex14_5.h"

int main(){
    Book book1(123, "CP5", "Lippman", "2012");
    Book book2(123, "CP6", "Lippman", "2012");

    if(book1 == book2)
        std::cout << book1 << std::endl;
    else
        std::cout << book1 << std::endl << book2 << std::endl;
    return 0;
}
