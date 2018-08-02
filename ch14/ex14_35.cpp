#include <string>
#include <iostream>

class PrintString{
    public:
    std::string operator()(std::istream &in){
        std::string tmp;
        getline(in,tmp);
        if(!in.fail())
            return tmp;
        else
            return std::string("");
    }
};

int main()
{
    PrintString ps;
    std::cout << ps(std::cin);
    return 0;
}
