#pragma once
#include <string>
#include <memory>
#include <iostream>

class StrVec{
    public:
        void reserve(std::size_t newcap);
        void resize(std::size_t newsize);
        void resize(std::size_t newsize, const std::string &s);
        void push_back(const std::string &s);
        StrVec():element(nullptr),cap(nullptr),first_free(nullptr){}
        StrVec(const StrVec &v);
        StrVec &operator=(const StrVec &v);
        ~StrVec();
        std::string *begin()const{return element;}
        std::string *end()const{return first_free;}
        std::size_t size(){return first_free-element;}
        std::size_t capacity(){return cap-element;}

    private:
        //called by constructor,destructor,operator=
        std::pair<std::string *,std::string *> alloc_n_copy(const std::string *beg,const std::string *end);

        //been called by push action.
        void chk_n_alloc();
        //destroy item and free memory.
        void free();

        //realloc much more memory and copy
        void reallocate();
        void alloc_n_move(std::size_t newcap);

    private:
        static std::allocator<std::string> alloc;
        std::string *element;
        std::string *cap;
        std::string *first_free;
};
