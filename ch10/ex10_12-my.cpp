#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

class Sales_data {
    public:
        Sales_data(const char * s){
            str = s;
        }
        Sales_data(const string &s){
            str = s;
        }
    public:
        string isbn(){return str;}
    private:
        string str;
};

bool compareIsbn(Sales_data & l, Sales_data& r){
    return l.isbn().size() < r.isbn().size();
}

int main(){
    Sales_data d1("aaa"),d2("b"),d3("cccc"),d4("23"),d5("234");
//    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    vector<Sales_data> v = {d1,d2,d3,d4,d5};
    sort(v.begin(),v.end(),compareIsbn);
    for (auto &s : v)
        std::cout << s.isbn() << " ";
    std::cout << std::endl;

    return 0;

}
