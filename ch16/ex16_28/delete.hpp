#pragma once

namespace cp5{
class Delete{
    public:
    template<typename T>
    void operator()(T *t){
        delete t;
    }
};
}
