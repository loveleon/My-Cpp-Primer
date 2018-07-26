#include "ex14_26_String.h"
#include <algorithm>

std::ostream& operator<<(std::ostream &out, const String &rhs){
    out << rhs.c_str() ;
    return out;
}

std::istream& operator>>(std::istream &in, String &rhs)
{
    for(char c;((c=in.get()) != '\n');){
        rhs.push_back(c);
    }

    return in;
}

bool operator==(const String &lhs, const String &rhs)
{
    return (lhs.size() == rhs.size() && std::equal(lhs.begin(),lhs.end(),rhs.begin()));
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
{
    return std::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
}

bool operator>(const String &lft, const String &rhs)
{
//    return std::lexicographical_compare(rhs.begin(),rhs.end(),lft.begin(),lft.end());
    return rhs < lft;
}

bool operator<=(const String &lft, const String &rhs)
{
    return !(rhs < lft);
}

bool operator>=(const String &lft, const String &rhs)
{
    return !(lft < rhs);
}


String::String(const char *s){
    char * sl = const_cast<char *>(s);
    while(*sl){
        ++sl;
    }

    range_initializer(s,++sl);
}

String::String(const String &rhs)
{
    //range_initializer(rhs.begin(),rhs.end());
    range_initializer(rhs.elements,rhs.first_free);
}

String& String::operator=(String &rhs){
    auto newstr = alloc_n_copy(rhs.elements,rhs.first_free);
    free();
    elements = newstr.first;
    first_free = cap = newstr.second;
    last_elem = first_free - 1;
    return *this;
}

String::String(String &&rhs)noexcept:elements(rhs.elements),last_elem(rhs.last_elem),first_free(rhs.first_free),cap(rhs.cap)
{
    rhs.elements = rhs.first_free = rhs.cap = rhs.last_elem = nullptr;
}

String& String::operator=(String &&rhs)noexcept
{
    if(this != &rhs){
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        last_elem = rhs.last_elem;
    }

    return *this;
}

String::~String()
{
    free();
}

void String::push_back(const char c)
{
   chk_n_alloc();
   *last_elem = c;
    last_elem = first_free;
    alloc.construct(first_free++,'\0');
}

void String::reallocate(){
    auto newsize = size() ?2*(size()+1):2;
    alloc_n_move(newsize);
}

void String::alloc_n_move(size_t sSize)
{
    auto newdata = alloc.allocate(sSize);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i = 0; i < size() +1;++i)
        alloc.construct(dest++,std::move(*elem++));
    free();
    elements = newdata;
    last_elem = dest - 1;
    first_free = dest;
    cap = elements + sSize;
}

void String::free()
{
    if(elements)
    {
        std::for_each(elements,first_free,[this](char &c){ alloc.destroy(&c); });
        alloc.deallocate(elements,cap-elements);
    }
}

std::pair<char *, char *> String::alloc_n_copy(const char * beg,const char *end)
{
    auto newstr = alloc.allocate(end-beg);
    return {newstr, std::uninitialized_copy(beg,end,newstr)};
}

void String::range_initializer(const char *beg, const char *end)
{
    auto newstr = alloc_n_copy(beg,end);
    elements = newstr.first;
    first_free = newstr.second;
    last_elem = first_free - 1;
    cap = newstr.second;
}

void String::reserve(size_t newcap)
{
    if(newcap < capacity())
        return;
    alloc_n_move(newcap);
}

void String::resize(size_t sSize,char c)
{
    if(sSize > size())
    {
        if(sSize > capacity())
            reserve(sSize*2);
        for(size_t i=size(); i < sSize;i++)
        {
            *last_elem++ = c;
            alloc.construct(first_free++,'\0');
        }
    }
    else if(sSize < size())
    {
        while(last_elem != elements + sSize)
        {
            --last_elem;
            alloc.destroy(--first_free);
        }
        *last_elem = '\0';
    }
}

void String::resize(size_t sSize)
{
    resize(sSize,' ');
}

