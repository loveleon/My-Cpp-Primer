#include <iostream>
#include <string>
#include "shared_pointer.h"
#include "delete.h"
#include "blob.h"
using std::string;

int main()
{
    Blob<string> b;
    b.push_back("sss");
    b[0] = "zzz";
   //b[] return vetor<T>
    std::cout << b[0] << std::endl;
    return 0;
}
