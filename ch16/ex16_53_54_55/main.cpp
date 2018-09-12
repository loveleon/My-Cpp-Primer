//ex16.53
#include <iostream>

template<typename T>
std::ostream& print(std::ostream& out, const T& t)
{
    out << t << "\t";
    return out;
}


//*
template<typename T,typename... Args>
std::ostream& print(std::ostream& out,const T& t, const Args& ... rest)
{
    out << t << ", ";
    print(out,rest...);
    return out;
}//*/

int main(){
    print(std::cout,1,2,3,"sss",1111.22)<<std::endl;
    print(std::cout,1)<<std::endl;
    print(std::cout,1,2) << std::endl;
    return 0;
}

//ex16.54
//complier error.

//ex16.55
//no match function.
