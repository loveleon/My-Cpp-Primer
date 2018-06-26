#pragma once
#include <string>

class StrVec{
    public:
        StrVec();
        StrVec(const StrVec &v);
        StrVec &operator=(const StrVec &v);

        void free();
        void alloc_n_copy();
    private:
        static std::allocator<std::string *> alloc;
        std::string *element;
        std::string *cap;
        std::string *first_free;
};
