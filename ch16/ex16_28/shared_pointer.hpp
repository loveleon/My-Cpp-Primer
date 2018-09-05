#pragma once
#include <functional>
#include <iostream>
#include "delete.hpp"

namespace cp5{
template<typename T> class SharedPointer;
template<typename T>
void swap(SharedPointer<T>& lft,SharedPointer<T>& rhs)
{
    std::cout << __func__ << __LINE__ << std::endl;
    using std::swap;
    swap(lft.ptr,rhs.ptr);
    swap(lft.ref_count,rhs.ref_count);
    swap(lft.deleter,rhs.deleter);
}

template<typename T>
class SharedPointer{
    public:
        friend void swap<T>(SharedPointer<T>& lft,SharedPointer<T>& rhs);
    public:
        //default.
        SharedPointer():ptr(nullptr),ref_count(new std::size_t(1)),deleter(cp5::Delete()){}
        //Ctor that takes raw pointer.
        explicit SharedPointer(T* raw_ptr):ptr(raw_ptr),ref_count(new std::size_t(1)),deleter(cp5::Delete()){}
        //copy constructor.
        SharedPointer(const SharedPointer& other):ptr(other.ptr),ref_count(other.ref_count),deleter(other.deleter){
            ++*ref_count;
        }
        //move constructor.
        SharedPointer(SharedPointer&& other):ptr(std::move(other.ptr)),ref_count(std::move(other.ref_count)),deleter(std::move(other.deleter)){
           //--*other.ref_count;
           //++*ref_count;
           other.ref_count = nullptr;
           other.ptr = nullptr;
        }
        //assigned operator
        SharedPointer& operator=(const SharedPointer& rhs)
        {
            //safe for self assignment.
            ++*ref_count;
            decrement_and_destroy();
            ptr = rhs.ptr;
            ref_count=rhs.ref_count;
            deleter = rhs.deleter;
            return *this;
        }
        //move assignment.
        SharedPointer operator=(SharedPointer&& rhs)noexcept
        {
            cp5::swap(*this,rhs);
            rhs.decrement_and_destroy();
            return *this;
        }
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
            return &*ptr;
        }
        //
        std::size_t use_count()const{
            return *ref_count;
        }
        //get underlay pointer
        T* get()const{
            return ptr;
        }
        bool unique()const{
            return 1 == *ref_count;
        }
        void swap(SharedPointer& rhs)
        {
            std::cout << __func__ << __LINE__ <<std::endl;
            cp5::swap(*this,rhs);
            //::swap(*this,rhs);
        }
        //free object if unique.
        void reset()
        {
            decrement_and_destroy();
        }
        //reset a raw pointer.
        void reset(T* pointer)
        {
            if(ptr != pointer)
            {
                decrement_and_destroy();
                ptr = pointer;
                ref_count = new std::size_t(1);
            }
        }
        //reset with raw pointer and deleter.
        void reset(T* pointer,std::function<void(T*)>& d)
        {
            reset(pointer);
            deleter = d;
        }
        //desconstructor.
        ~SharedPointer()
        {
            decrement_and_destroy();
        }
    private:
        T* ptr;
        std::size_t * ref_count;
        std::function<void(T*)> deleter;
        void decrement_and_destroy()
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
};
}//end namespace cp5
