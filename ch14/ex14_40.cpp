#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using std::vector;
using std::string;
using std::sort;

class ShorterString{
    public:
        bool operator()(const string& lft, const string& rhs){return lft.size() < rhs.size();}
};

class BiggerEqual{
    public:
        BiggerEqual(size_t sz):sz_(sz){}
        bool operator()(const string& str){return str.size() >= sz_;}
    private:
        size_t sz_;
};

class Print{
    public:
        void operator()(const string& str)
        {
            std::cout << str << " ";
        }
};

string make_pular(size_t ctr, const string &word, const string& ending)
{
    return (ctr > 1)? word + ending: word;
}

void elimDups(vector<string> &vec)
{
    sort(vec.begin(),vec.end());
    auto pos = std::unique(vec.begin(),vec.end());
    vec.erase(pos , vec.end());
}

void biggies(vector<string> &vec,vector<string>::size_type sz)
{
    elimDups(vec);
    std::stable_sort(vec.begin(),vec.end(),ShorterString());
    auto pos = find_if(vec.begin(),vec.end(),BiggerEqual(sz));
    auto count = vec.end() - pos;
    std::cout << count << make_pular(count," word","s") << " of length " << sz << " or longer." << std::endl;
    for_each(pos,vec.end(),Print());
    std::cout << std::endl;
}

int main(){
    vector<string> vec{ "fox", "jumps", "over", "quick", "red", "red", "slow", "the", "turtle" };
    biggies(vec,4);
    return 0;
}

