#pragma once
#include <functional>
#include <memory>
#include <iostream>
#include "delete.h"

template<typename T> class SharedPointer;
template<typename T>
void swap(SharedPointer<T>& lft,SharedPointer<T>& rhs);
/*
{
    std::cout << __func__ << __LINE__ << std::endl;
    using std::swap;
    swap(lft.ptr,rhs.ptr);
    swap(lft.ref_count,rhs.ref_count);
    swap(lft.deleter,rhs.deleter);
}
*/

template<typename T>
class SharedPointer{
    public:
        friend void swap<T>(SharedPointer<T>& lft,SharedPointer<T>& rhs);
    public:
        //default.
        SharedPointer() = default;

        //Ctor that takes raw pointer.
        explicit SharedPointer(T* up,std::function<void(T*)> _delter = Delete()):ptr(up),ref_count(new std::size_t(1)),deleter(_delter) {}

        //Ctor sp is rvalue.
        explicit SharedPointer(std::shared_ptr<T>&& sp,std::function<void(T*)> _d = Delete());

        //copy constructor.
        SharedPointer(const SharedPointer& other):ptr(other.ptr),ref_count(other.ref_count),deleter(other.deleter){
            ++*ref_count;
        }

        //move constructor.
        SharedPointer(SharedPointer&& other)noexcept;

        //assigned operator
        SharedPointer& operator=(const SharedPointer& rhs);

        //move assignment.
        SharedPointer& operator=(SharedPointer&& rhs)noexcept;

        //conversion to bool
        operator bool()const
        {
            return ptr?true:false;
        }
        //dereference
        T& operator* ()const{
            return *ptr;
        }
        //arrow
        T* operator->()const{
            return & this->operator* ();
        }
        //
        std::size_t use_count()const{
            return *ref_count;
        }
        //get underlay pointer
        T* get()const noexcept{
            return ptr;
        }

        //check unique user.
        bool unique()const noexcept{
            return 1 == *ref_count;
        }

        void swap(SharedPointer& rhs)
        {
            std::cout << __func__ << __LINE__ <<std::endl;
            ::swap(*this,rhs);
        }

        //free object if unique.
        void reset()
        {
            decrement_and_destroy();
        }
        //reset a raw pointer.
        void reset(T* p);

        //reset with raw pointer and deleter.
        //reset to point where p is pointing and change deleter to d
        void reset(T* p,std::function<void(T*)>& d)
        {
            reset(p);
            deleter = d;
        }

        //desconstructor.
        ~SharedPointer()
        {
            decrement_and_destroy();
        }
    private:
        T* ptr = nullptr;
        std::size_t * ref_count = new std::size_t(0);
        std::function<void(T*)> deleter{Delete()};
        void decrement_and_destroy();
            /*
        {
            if(ptr && --*ref_count)
            {
                delete ref_count;
                deleter(ptr);
            }else if(!ptr)
            {
                delete ref_count;
            }

            ref_count = nullptr;
            ptr       = nullptr;
        }
        */
};

template<typename T>
inline
void swap(SharedPointer<T>& lft,SharedPointer<T>& rhs)
{
    using std::swap;
    swap(lft.ptr,rhs.ptr);
    swap(lft.ref_count,rhs.ref_count);
    swap(lft.deleter,rhs.deleter);
}

/**
 *  @brief  ctor taking std::shared_ptr&& i.e. rvalue reference
 *  an interface between shared_pointer and std::shared_ptr.
 *  only rvalue AND unique ownership can use this ctor.
 */
template<typename T>
inline
SharedPointer<T>::SharedPointer(std::shared_ptr<T>&& sp,std::function<void(T*)> _d)
{
    if(sp.unique())
        *this = SharedPointer(new T(*sp),_d);
    else
        throw std::runtime_error("only unique and rvalue can transfer ownshiip.");
}

///move constructor.
template<typename T>
inline
SharedPointer<T>::SharedPointer(SharedPointer&& sp)noexcept :
    ptr(sp.ptr),ref_count(sp.ref_count),deleter(std::move(sp.deleter))
{
    sp.ptr = nullptr;
    sp.ref_count = nullptr;
}

//copy assignment.
template<typename T>
inline
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer& sp){
    // prevent self-assignment ,first increment ref_count.
    ++*ref_count;
    decrement_and_destroy();
    ptr = sp.ptr;
    ref_count = sp.ref_count;
    deleter = sp.deleter;
}

//move assignment.
template<typename T>
inline SharedPointer<T>& SharedPointer<T>::operator=(SharedPointer&& sp)noexcept
{
    decrement_and_destroy();
    ::swap(*this,sp);
    std::cout << __func__ << " SharedPointer:move="<< std::endl;
    return *this;
}

//reset ptr to ponint to new ptr and create a new ref_count
//for it
template<typename T>
inline void
SharedPointer<T>::reset(T* p)
{
    if(ptr != p)
    {
        decrement_and_destroy();
        ptr = p;
        ref_count = new std::size_t(1);
    }
}

template<typename T>
inline std::ostream& operator<<(std::ostream& out,const SharedPointer<T>& sp)
{
    out << sp.get();//get is const .so sp definition const .
    return out;
}

//decrement and delete using deleter.
template<typename T>
void SharedPointer<T>::decrement_and_destroy(){
    if(ptr)
    {
        if(--*ref_count == 0)
        {
            delete ref_count;
            deleter(ptr);
        }
        ref_count = nullptr;
        ptr = nullptr;
    }
}
