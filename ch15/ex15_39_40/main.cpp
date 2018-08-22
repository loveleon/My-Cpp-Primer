#include <iostream>
#include <fstream>

#include "textquery.h"
#include "query.h"

int main()
{
    std::ifstream is("../ex15_39_40/test.txt");

    TextQuery t(is);
    //Query q = Query("fieryzzz") | Query("wind");
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout <<q.eval(t) << std::endl;

    return 0;
}
