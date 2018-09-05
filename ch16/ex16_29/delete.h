#pragma once
#include <iostream>

class Delete{
    public:
        Delete() = default;
    template<typename T>
    void operator()(T *t){
        delete t;
    }
};

class DebugDelete{
    public:
        template<typename T> void operator()(T *t){
            delete t;
        }
};
