#include "ex13_49_String.h"

int main(){
    const char *str = "123";

    String str2(str);
    String str3 = std::move(str2);
    print(std::cout ,str3) << std::endl;
    print(std::cout ,str2) << std::endl;
    return 0;
}
