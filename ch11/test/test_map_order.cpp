#include "../common.h"

int main(){
    map<string,string> mapm = {{"cxh","cxh"},
                                {"zzz","zzz"},
                                {"yyy","yyy"},
                                {"xxx","xxx"},
                                {"hhh","hhh"},
                                {"caa","caa"}
    };
    for(const auto m: mapm){
        cout << m.first << " -> "<< m.second<<endl;
    }

    return 0;
}
