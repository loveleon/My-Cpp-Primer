#pragma once
#include <memory>
#include <iostream>
#include <cstring>
#include <algorithm>

class String{
    public:
        friend std::ostream & print(std::ostream &out, const String &str);
    public:
        String();
        String(const char *str);
        String(const String &str);
        String &operator=(const String &str);
        ~String();
    private:
        char * element;
        char * end;
        std::pair<char*,char*> alloc_n_copy(const char *beg,const char *end);
        void range_initialize(const char *start,const char *end);
        void free();
        std::allocator<char>  alloc;
};

std::ostream & print(std::ostream &out, const String &str);
