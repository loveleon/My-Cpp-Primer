#pragma once
#include <iostream>

namespace cp5{
class Delete{
    public:
        Delete() = default;
    template<typename T>
    void operator()(T *t){
        delete t;
    }
};
}// namespace cp5

class DebugDelete{
    public:
        template<typename T> void operator()(T *t){
            delete t;
        }
};
