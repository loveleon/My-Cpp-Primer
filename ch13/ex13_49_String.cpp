#include "ex13_49_String.h"
#include <algorithm>

std::pair<char *, char *>
String::alloc_n_copy(const char *b, const char *e){
    auto str = alloc.allocate(e - b);
    return {str,std::uninitialized_copy(b, e, str) };
}

void String::range_initializer(const char *first, const char *second){
    auto str = alloc_n_copy(first,second);
    elements = str.first;
    end = str.second;
}

String::String(const char *s){
    char *sl = const_cast<char *>(s);
    while(*sl)
        ++sl;
    range_initializer(s,++sl);
}

String::String(const String &str){
    range_initializer(str.elements,str.end);
    std::cout << "copy constructor." << std::endl;
}

void String::free(){
    if(elements){
        std::for_each(elements,end,[this](char &c){alloc.destroy(&c);});
        alloc.deallocate(elements,end - elements);
    }
}

String::~String(){
    std::cout << __func__ << std::endl;
    free();
}

String &String::operator=(const String &rhs){
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    std::cout << " copy-assignment." << std::endl;
    return *this;
}

String &String::operator=(String &&s) noexcept{
    std::cout << "move-assignment." << std::endl;
    if(this != &s){
        free();
        elements = std::move(s.elements);
        end = std::move(s.end);
        s.elements = s.end = nullptr;
    }
    return *this;
}

String::String(String &&s) noexcept : elements(s.elements),end(s.end){
    std::cout << "move constructor." << std::endl;
//    elements = std::move(s.elements);
//    end = std::move(s.end);
    s.elements = s.end = nullptr;
}

std::ostream &print(std::ostream &out, const String &str){
    std::for_each(str.elements,str.end,[&out](const char &ch){ out << ch << " "; });
    return out;
}
