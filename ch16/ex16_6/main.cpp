/*
 * ex16_6 std::begin return reference of array begin iterator.
 *          std::end return reference of array last item past one postion iterator.
 */
#include <iostream>
#include <vector>
#include <list>
#include <string>
using std::cout;using std::endl;
using std::vector;using std::list;
using std::string;

namespace ex16_6 {
template<typename T, unsigned U>
T* begin(T (&arr)[U])
{
    return arr;
}

template<typename T,unsigned U>
T* end(T (&arr)[U])
{
    return arr+U;
}

}

int main()
{
    vector<int> ivec = {1,2,3,4,5,6};
    string sLst[] = {"cxh","qwe","rty","tyu"};
    cout << *ex16_6::begin(sLst) << endl;
    cout << *(ex16_6::end(sLst)-1) << endl;

    return 0;
}
