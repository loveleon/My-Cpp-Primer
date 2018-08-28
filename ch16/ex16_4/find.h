#pragma once

namespace ex16{
    template<typename T, typename U>
    T find(T first,T last,U const &val)
    {
        for(;first!=last && *first != val;++first)
            ;
        return first;
    }
}
