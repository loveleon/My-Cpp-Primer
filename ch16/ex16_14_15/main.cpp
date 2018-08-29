#include "screen.h"

int main()
{
    Screen<5,5> s1('c');
    Screen<5,5> s2;

    std::cout << s1 ;
    std::cin >> s2;
    std::cout << s2;
    return 0;
}
