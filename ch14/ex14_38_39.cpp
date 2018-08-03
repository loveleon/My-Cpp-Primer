#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;

class CheckStrSize{
    public:
        CheckStrSize(size_t _lower, size_t _upper):lower(_lower),upper(_upper){}
        bool operator()(const string& str){
            return str.size() >= lower && str.size() <= upper;
        }
        size_t getLower()const {return lower;}
        size_t getUpper()const {return upper;}
    private:
        size_t lower;
        size_t upper;
};

int main(){
    vector<CheckStrSize> vec;
    std::size_t lower = 1;
    auto uppers = {3u,4u,5u,6u,7u,8u,9u,10u,11u,12u,13u,14u};
    //
    for(auto upper : uppers)
        vec.push_back(CheckStrSize(lower,upper));

    std::map<size_t,size_t> count;
    for(auto upper : uppers)
        count[upper] = 0;

    ifstream ifile("../ex14_38_39.cpp",ifile.in);
    string tmp;
    for(string tmp;ifile >> tmp;)
    {
        for(auto is_range : vec)
        {
            if(is_range(tmp))
                ++count[is_range.getUpper()];
        }

    }

    for(auto pair : count)
        std::cout << "range in [1 " << pair.first << " ]:" << pair.second << std::endl;

    return 0;
}
