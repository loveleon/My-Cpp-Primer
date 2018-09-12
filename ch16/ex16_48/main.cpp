#include <iostream>
#include <sstream>
#include <string>

template<typename T> std::string debug_req(const T& );
template<typename T> std::string debug_req(T* );

std::string debug_req(char *);
std::string debug_req(const char* );
std::string debug_req(const std::string &s);

template<typename T> std::string debug_req(const T& t)
{
    std::ostringstream str;
    str << t;
    return str.str();
}

template<typename T> std::string debug_req(T* t)
{
    std::ostringstream os;
    if(t)
        os << " pointer :" << t;
    else
        os << "null pointer.";
    return os.str();

}

std::string debug_req(char* s)
{
    return debug_req(std::string(s));
}

std::string debug_req(const char* s)
{
    return debug_req(std::string(s));
}

std::string debug_req(const std::string &s )
{
    return '"' + s + '"';

}
