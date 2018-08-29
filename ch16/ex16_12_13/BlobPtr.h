#pragma once
#include <memory>
#include <vector>
#include <exception>

#include "Blob.h"

template<typename> class BlobPtr;
template<typename T> bool operator==(const BlobPtr<T>& ,const BlobPtr<T>& );
template <typename T> bool operator<(const BlobPtr<T>& ,const BlobPtr<T>& );
template<typename T>
class BlobPtr{
    public:
        friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
        friend bool operator < <T>(const BlobPtr<T>& ,const BlobPtr<T>& );
    public:
        BlobPtr():curr(0){}
        BlobPtr(Blob<T>& b,std::size_t sz):wptr(b.data),curr(sz){}

        T& operator*()const{
            auto p = check(curr,"dereference past end.");
            return (*p)[curr];
        }

        //prefix
        BlobPtr& operator++();
        BlobPtr& operator--();

        //postfix
        BlobPtr operator++(int);
        BlobPtr operator--(int);

    private:
        std::shared_ptr<std::vector<T>> check(std::size_t,const std::string& msg)const;
        std::weak_ptr<std::vector<T>> wptr;
        std::size_t curr;
};

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr,"increase past end of StrBlob.");
    ++curr;
    return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    check(--curr,"decrement past begin of StrBlob.");
    return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr bp = *this;
    ++*this;
    return bp;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr bp = *this;
    --*this;
    return bp;
}

template<typename T>
bool operator ==(const BlobPtr<T>& lft, const BlobPtr<T>& rhs)
{
    if(lft.wptr.lock() != rhs.wptr.lock())
        throw std::runtime_error("point to different StrBlob.");
    return lft.curr == rhs.curr;
}

template<typename T>
bool operator <(const BlobPtr<T>& lft, const BlobPtr<T>& rhs)
{
    if(lft.wptr.lock() != rhs.wptr.lock())
        throw std::runtime_error("point to different StrBlob.");
    return lft.curr < rhs.curr;
}
