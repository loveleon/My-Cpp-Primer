#include "comm/comm.h"
string (*get_array())[3]{
   static string tmp[3] = {"123","456","789"};
//    string tmp[10] = new string[5]({"123","456","789","cxg","sfad"});
    auto str = &tmp;
    return str;
}
int main(void){
    auto arr = get_array();
    for( auto s : *arr )
        cout << s << " ";
    return 0;
}
