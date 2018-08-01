#include "ex14_32.h"
#include <iostream>
StrBlobPtr& StrBlobPtr_pointer::operator*()const
{
    return *pointer;
}

StrBlobPtr* StrBlobPtr_pointer::operator->()const
{
    return pointer;
}


int main()
{
    StrBlob sb1{"hello","boy"};
    StrBlobPtr iter(sb1);

    StrBlobPtr_pointer p(&iter);
    std::cout << p->deref() << std::endl;

    return 0;

}
