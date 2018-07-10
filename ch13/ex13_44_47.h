#pragma once
#include <memory>
#include <iostream>

class String{
    public:
        friend std::ostream &print(std::ostream &out, const String &str);
    public:
        String():String(""){}
        String(const char *s);
        String(const String &s);
        String &operator=(const String &s);
        ~String();

        //const char * c_str()const{return elements;}
        //size_t size() const {return end - elements;}
        //size_t length() const {return end - elements - 1;}

    private:
        std::pair<char *,char *> alloc_n_copy(const char *b, const char *e);
        void range_initializer(const char *first, const char *second);
        void free();
    private:
        char * elements;
        char * end;
        std::allocator<char> alloc;
};

std::ostream &print(std::ostream &out, const String &str);
