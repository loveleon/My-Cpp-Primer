#include "wy_textquery.h"
#include "wy_queryresult.h"
#include "debugdelete.h"
#include <fstream>

int main()
{
    std::ifstream inFile("../ex16_21_22/wy_textquery.h",std::ios::in);
    if(inFile)
        std::cout << "true" << std::endl;
    else
        std::cerr << "false" << std::endl;

    wy_textQuery tq(inFile);
    std::cout << "input word:" << std::endl;
    std::string word;
    std::cin >> word;
    auto qr = tq.query(word);
    std::cout << qr.getCounter() << "\t" << qr.getQueryWord() << "\t";
    print(std::cout,qr);

    return 0;
}

