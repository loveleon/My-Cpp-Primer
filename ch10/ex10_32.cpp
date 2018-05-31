#include "Sales_item.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

using std::cin;
using std::cout;
using std::vector;
using std::endl;


int main(){
    std::istream_iterator<Sales_item> in(cin),ineof;
    std::ostream_iterator<Sales_item> out(cout," ");
    vector<Sales_item> vec;
    std::copy(in,ineof,std::back_inserter(vec));
    std::sort(vec.begin(),vec.end(),compareIsbn);
    for(auto it = vec.cbegin(),pos = it;it != vec.cend();it = pos){
         pos = std::find_if(vec.cbegin(),vec.cend(),[it](const Sales_item & item){return item.isbn() != (*it).isbn();});
        auto sum = std::accumulate(it,pos,Sales_item(it->isbn()));
        cout << (*it).isbn() << " and sum :" << sum << endl;
//        it = pos;
    }
    return 0;
}
