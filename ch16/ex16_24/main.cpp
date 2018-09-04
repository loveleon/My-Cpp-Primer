#include <iostream>
#include "Blob.h"
#include "BlobPtr.h"

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6};
    Blob<int> b(vec.begin(),vec.end());

    std::cout << "Blob<int> b size:" << b.size() << std::endl;

    return 0;
}
