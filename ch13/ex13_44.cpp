#include "ex13_44.h"
String::~String(){
    free();
}
String::String():element(nullptr),end(nullptr){

}

String &String::operator=(const String &str){
    auto data = alloc_n_copy(str.element,str.end);
    free();
    range_initialize(data.first,data.second);
    element = data.first;
    end = data.second;
    return *this;
}
/*
String::String(const char *str){
    int len = strlen(str);
    auto start = alloc.allocate(len);
    for(int i = 0; i < len; ++i){
        alloc.construct(start,str[i]);
    }
    element = const_cast<char *>(str);
    end = element+len;
}*/

String::String(const char *str){
    char * start = const_cast<char *>(str);
    while(*start){
        std::cout << *start << " ";
        ++start;
    }
    std::cout << std::endl;
    range_initialize(str,++start);
}

String::String(const String &str){
    range_initialize(str.element,str.end);
}

void String::range_initialize(const char *start, const char *end){
    auto data = alloc_n_copy(start,end);
    element = data.first;
    end = data.second;
}

std::pair<char*,char*> String::alloc_n_copy(const char *beg, const char *end){
    auto data = alloc.allocate(end-beg);
    return {data,std::uninitialized_copy(beg,end,data)};
}

void String::free(){
    if(element){
        std::for_each(element,end,[this](char &ch){alloc.destroy(&ch);});
        //std::for_each(element,end,[this](const char &ch){alloc.destroy(&ch);});
        alloc.deallocate(element,end-element);
    }
}

std::ostream & print(std::ostream &out, const String &str){
//    std::for_each(str.element,str.end,[&out](const char &ch){out << ch << " ";});
    out << str.element ;
    return out;
}
