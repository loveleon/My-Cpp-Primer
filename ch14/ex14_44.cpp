#include <iostream>
#include <functional>
#include <cassert>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::function;

class Div{
    public:
//        Div(const int _lft,const int _rhs):lft(_lft),rhs(_rhs){}
        int operator()(const int lft,const int rhs){
            assert(rhs != 0);
            return lft/rhs;
        }
    private:
        int lft,rhs;
};
int main(){
    auto add = [](const int lft,const int rhs)->int{return lft+rhs;};
    auto minus = [](const int lft,const int rhs)->int{return lft-rhs;};
    auto multiplies = [](const int lft,const int rhs)->int{return lft*rhs;};
    auto div = [](const int lft,const int rhs)->int{assert(rhs != 0);
         return lft/rhs;
    };

    auto mod = [](const int lft,const int rhs)->int{return lft%rhs;};

    map<string,function<int (const int,const int)>> mMap;
    mMap.insert({"+",add});
    mMap.insert({"-",minus});
    mMap.insert({"--",std::minus<int>()});
    mMap.insert({"*",multiplies});
    mMap.insert({"/",div});
    mMap.insert({"//",Div()});
    mMap.insert({"%",mod});

    std::cout << "+" << mMap["+"](10,5) << endl;
    std::cout << "-" << mMap["-"](10,5) << endl;
    std::cout << "--" << mMap["--"](10,5) << endl;
    cout << "*" << mMap["*"](10,5) << endl;
    cout << "/" << mMap["/"](10,5) << endl;
    cout << "//" << mMap["//"](10,5) << endl;
    cout << "%" << mMap["%"](10,5) << endl;

    return 0;
}
