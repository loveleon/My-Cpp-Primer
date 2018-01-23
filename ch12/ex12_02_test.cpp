#include "ex12_02-my.h"

int main(){
    /*
    StrBob b1;
    {
        StrBob  b2= {"one","two","three"};
        b1 = b2;
        b2.push_back("for");
        std::cout << "b2 size:" << b2.size() << std::endl;
    }
    std::cout << "b1 size:" << b1.size() << std::endl;
*/
    const StrBob csb{"123","234","345"};
    StrBob sb{"aa","bb","cc"};
    sb.back() = "dd";
    std::cout << "front:" << csb.front() << ",back:" << csb.back() << std::endl;
    std::cout << "front:" << sb.front() << ",back:" << sb.back() << std::endl;



    return 0;

}
