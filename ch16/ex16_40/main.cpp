#include <algorithm>
template<typename IT>
auto fcn3(IT beg,IT end)->typename std::remove_reference<decltype(*beg)>::type{
    return *beg;
}
