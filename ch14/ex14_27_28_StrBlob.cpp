#include "ex14_27_28_StrBlob.h"
#include <algorithm>

//StrBlob operator
bool operator==(const StrBlob &lft, const StrBlob &rhs)
{
    return *lft.data == *rhs.data;
}

bool operator!=(const StrBlob &lft, const StrBlob &rhs)
{
    return !(lft == rhs);
}

bool operator<(const StrBlob &lft, const StrBlob &rhs)
{
    return std::lexicographical_compare(lft.data->begin(),lft.data->end(),rhs.data->begin(),rhs.data->end());
}

bool operator>=(const StrBlob &lft, const StrBlob &rhs)
{
    return !(lft < rhs);
}

bool operator<=(const StrBlob &lft, const StrBlob &rhs)
{
    return !(rhs < lft);
}

bool operator>(const StrBlob &lft, const StrBlob &rhs)
{
    return rhs<lft;
}

//StrBlobPtr operator
bool operator==(const StrBlobPtr &lft, const StrBlobPtr &rhs)
{
    return lft.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lft, const StrBlobPtr &rhs)
{
    return !(lft.curr == rhs.curr);
}

bool operator<(const StrBlobPtr &lft, const StrBlobPtr &rhs)
{
    return lft.curr < rhs.curr;
}

bool operator<=(const StrBlobPtr &lft, const StrBlobPtr &rhs)
{
    return !(rhs < lft);
}

bool operator>(const StrBlobPtr &lft, const StrBlobPtr &rhs)
{
    return rhs < lft;
}

bool  operator>=(const StrBlobPtr &lft, const StrBlobPtr &rhs)
{
    return !(rhs < lft);
}

//ConStrBlobPtr
bool operator==(const ConstStrBlobPtr &lft, const ConstStrBlobPtr &rhs)
{
    return lft.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lft, const ConstStrBlobPtr &rhs)
{
    return !(lft.curr == rhs.curr);
}

bool operator<(const ConstStrBlobPtr &lft, const ConstStrBlobPtr &rhs)
{
    return lft.curr < rhs.curr;
}

bool operator<=(const ConstStrBlobPtr &lft, const ConstStrBlobPtr &rhs)
{
    return lft.curr <= rhs.curr;
}

bool operator>(const ConstStrBlobPtr &lft, const ConstStrBlobPtr &rhs)
{
    return lft.curr > rhs.curr;
}

bool  operator>=(const ConstStrBlobPtr &lft, const ConstStrBlobPtr &rhs)
{
    return lft.curr >= rhs.curr;
}

//StrBlob
StrBlob& StrBlob::operator=(const StrBlob &rhs)
{
    data = make_shared<vector<string>>(*rhs.data);
    return *this;
}

StrBlob& StrBlob::operator=(StrBlob &&rhs)noexcept
{
    if(*this != rhs){
        data = std::move(rhs.data);
        rhs.data = nullptr;
    }

    return *this;
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this,data->size());
}

ConstStrBlobPtr StrBlob::cbegin()const
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend()const
{
    return ConstStrBlobPtr(*this,data->size());
}
