#pragma once
#include <memory>
#include <iostream>
#include <string>
#include <algorithm>

class String{
    public:
        friend std::ostream & print(std::ostream &out, const String &str);
    public:
        String():String(""){}
        String(const char *str);
        String(const String &str);
        String &operator=(const String &str);
        ~String();
        const char *c_str() const { return element; }
        size_t size() const { return end - element; }
        size_t length() const { return end - element - 1; }

    private:
        char * element;
        char * end;
        std::allocator<char>  alloc;

        std::pair<char*,char*> alloc_n_copy(const char *beg,const char *end);
        void range_initialize(const char *start,const char *end);
        void free();
};

std::ostream & print(std::ostream &out, const String &str);
