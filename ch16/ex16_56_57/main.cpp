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
template<typename T>
std::ostream& print(std::ostream& out,const T& t)
{
    out << t ;
    return out;
}

template<typename T,typename... Args>
std::ostream& print(std::ostream& out, const T& t,const Args& ... args)
{
    out << t << ", ";
    return print(out,args...);
}

template<typename... Args>
std::ostream& err_msg(std::ostream& out,const Args... args)
{
    return print(out,debug_req(args)...);
}

int main(){
    err_msg(std::cout,1,2,3,4,9.0f,"sss","alan");
    return 0;
}
