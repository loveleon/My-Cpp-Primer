#pragma once
#include <iostream>
#include <memory>

class String{
    friend std::ostream &operator<<(std::ostream &out, const String &);
    friend std::istream &operator>>(std::istream &in , String &);
    friend bool operator==(const String& lhs, const String &rhs);
    friend bool operator!=(const String& lhs, const String &rhs);
    friend bool operator<(const String& lhs, const String &rhs);
    friend bool operator<=(const String &lhs,const String &rhs);
    friend bool operator>(const String &lhs, const String &rhs);
    friend bool operator>=(const String &lhs, const String &rhs);
    public:
        String():String(""){}
        String(const char *s);
        String& operator=(String &rhs);
        String(const String &rhs);
        String(String &&rhs)noexcept;
        String& operator=(String &&rhs)noexcept;
        ~String();
    public:
        void push_back(const char c);
        char *begin(){return elements;}
        char *end(){return last_elem;}
        char& operator[](size_t i){return elements[i];}
        const char& operator[](size_t i)const{return elements[i];}
    private:
        std::pair<char *,char *> alloc_n_copy(const char *beg,const char *end);
        void range_initializer(const char *beg,const char *end);
        void free();
        void reallocate();
        void alloc_n_move(size_t new_cap);
        void chk_n_alloc(){if(first_free == cap) reallocate();}

    private:
        char * elements;
        char * last_elem;
        char * first_free;
        char * cap;
        std::allocator<char> alloc;
};
