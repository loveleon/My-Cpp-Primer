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
        String(const char *s);
    private:
        std::pair<char *,char *> alloc_n_copy(const char *beg,const char *end);


    private:
        char * elements;
        char * last_elem;
        char * first_free;
        char * cap;
        std::allocator<char> alloc;
};
