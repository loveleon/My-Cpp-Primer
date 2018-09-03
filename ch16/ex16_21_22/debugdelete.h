#pragma once
#include <iostream>

class DebugDelete{
    public:
        DebugDelete(std::ostream &out = std::cerr):os(out){}
        template<typename T> void operator()(T* t)
        {
            os << "deleting pointer " << std::endl;
            delete t;
        }

    private:
        std::ostream &os;
};
