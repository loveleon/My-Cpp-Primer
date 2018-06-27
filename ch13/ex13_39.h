#pragma once
#include <string>

class StrVec{
    public:
        StrVec():element(nullptr),cap(nullptr),first_free(nullptr){}
        StrVec(const StrVec &v);
        StrVec &operator=(const StrVec &v);
        ~StrVec();
        std::string *begin(){return element;}
        std::string *end(){return first_free;}
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

    private:
        static std::allocator<std::string> alloc;
        std::string *element;
        std::string *cap;
        std::string *first_free;
};
