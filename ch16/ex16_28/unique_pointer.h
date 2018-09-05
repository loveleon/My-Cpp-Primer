#pragma once
#include <iostream>
#include "delete.hpp"

namespace cp6{
template <typename T,typename D> class unique_pointer;
template<typename T,typename D>
void swap(unique_pointer<T,D>& lft,unique_pointer<T,D>& rhs);
}

template<typename T,typename D = DebugDelete>
class unique_pointer{
    public:
       friend void cp6::swap(unique_pointer<T,D>& lft,unique_pointer<T,D>& rhs);
    public:
        unique_pointer(const unique_pointer& up) = delete;
        unique_pointer& operator=(const unique_pointer& up) = delete;

        //default ctor and a parameter ctor.
        unique_pointer() = default;
        explicit unique_pointer( T* up):ptr(up){}//const T* UP

        //move ctor.
        unique_pointer(unique_pointer&& up)noexcept:ptr(up.ptr){
            up.ptr = nullptr;
        }

        //move assignment.
        unique_pointer& operator=(unique_pointer&& up)noexcept;
        unique_pointer& operator=(std::nullptr_t n)noexcept;

        //operator overload :* -> bool
        T& operator *()const {
            return *ptr;
        }
        T* operator ->()const{return &this->operator*();}
        operator bool()const {return ptr?true:false;}

        T* get()const {
            return ptr;
        }

        //swap member use the friend swap.
        void swap(unique_pointer& rhs){
            using std::swap;
            swap(ptr,rhs.ptr);
            swap(deleter,rhs.deleter);
        }

        //free and make it point to nullptr or `new ptr` s ptr
        //
        void reset(T* _ptr = nullptr)
        {
            deleter(ptr);
            ptr = _ptr;
        }

        //release ptr and make ptr to nullptr;
        T* release();

        //descontructor. dctor
        ~unique_pointer()
        {
            deleter(ptr);
        }
    private:
        T* ptr = nullptr;
        D deleter = D();
};

namespace cp6{
template<typename T,typename D>
void swap(unique_pointer<T,D>& lft,unique_pointer<T,D>& rhs)
{
    using std::swap;
    swap(lft.ptr,rhs.ptr);
    swap(lft.deleter,rhs.deleter);
}
}

template<typename T,typename D> inline
unique_pointer<T,D>& unique_pointer<T,D>::operator=(unique_pointer&& rhs)noexcept
{
    //prevent self-assignment.
    if(this != &rhs)
    {
        /*
        //one method.
        cp6::swap(*this,rhs);
        deleter(rhs.ptr);
        rhs.ptr = nullptr;
        */


        //other
        /*
        deleter(ptr);
        ptr = nullptr;
        ::swap(*this,rhs);
        */
        reset();
        ptr = rhs.ptr;
        deleter = std::move(rhs.deleter);
        rhs.ptr = nullptr;
    }
    return *this;
}

template<typename T,typename D> inline
unique_pointer<T,D>& unique_pointer<T,D>::operator=(std::nullptr_t n)noexcept
{
    if(n == nullptr)
    {
        deleter(ptr);
        ptr = nullptr;
    }
    return *this;
}

template<typename T,typename D>
inline
T* unique_pointer<T,D>::release()
{
    T* ret = ptr;
    ptr = nullptr;
    return ret;
}
