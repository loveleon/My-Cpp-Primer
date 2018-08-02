#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

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
    vector<string> vec;
    vec.reserve(10);
    PrintString ps;
    for(string tmp;!(tmp = ps(std::cin)).empty();)
        vec.push_back(tmp);
    for_each(vec.begin(),vec.end(),[](const string &str){ std::cout << str << " "; });
    return 0;
}
