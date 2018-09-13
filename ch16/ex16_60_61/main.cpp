//ex16.60
//make_shared should be a variadic template function that forwards all argument to underlying constructor that
//allocate and initializes an object in dynamic memory and ,at least,build a shared_ptr by wrapping the raw pointer.
//
//ex16.61
//
#include <iostream>
#include <memory>
#include <utility>

namespace ch16{
    template<typename T,typename... Args>
    auto make_shared(Args&& ...args)->std::shared_ptr<T>
    {
        return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
    }
}// namespace ch16

struct Foo{
    explicit Foo(int _i):i(_i){}
    int i = 0;
};

int main(){
    auto num  = ch16::make_shared<int>(42);
    std::cout << *num << std::endl;

    auto str = ch16::make_shared<std::string>(10,'c');
    std::cout << *str << std::endl;

    auto foo = ch16::make_shared<Foo>(99);
    std::cout << foo->i << std::endl;

    return 0;
}
