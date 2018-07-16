#include "ex13_58.h"
#include <algorithm>

Foo::Foo(std::initializer_list<int> list){
    copy(list.begin(),list.end(),std::back_inserter(data));
}

Foo Foo::sorted() const & {
//    Foo ret(*this);
//    sort(ret.data.begin(),ret.data.end());
    std::cout << "left value version called." <<std::endl;
//    return ret;
    return Foo(*this).sorted();
}

Foo Foo::sorted() && { // 使用在右值
    // 右值可以直接排序
    sort(data.begin(),data.end());
    std::cout << "right value version called." << std::endl;
    return *this;
}

std::ostream & print(std::ostream &out, const Foo &f){
    std::for_each(f.data.cbegin(),f.data.cend(),[&out](const int &i){ out << i << " "; });
    return out;
}
