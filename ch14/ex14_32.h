#pragma once
#include "ex14_30_StrBlob.h"
class StrBlobPtr;
class StrBlobPtr_pointer{
    public:
        StrBlobPtr_pointer() = default;
        StrBlobPtr_pointer(StrBlobPtr *p):pointer(p){}
        StrBlobPtr& operator*()const;
        StrBlobPtr* operator->()const;
    private:
        StrBlobPtr *pointer = nullptr;
};
