#include "ex12_19.h"
#include <fstream>
using std::ifstream;

int main(){
    ifstream in("../ex12_19.h",in.in);
    string line;
    StrBlob sb;
    while(getline(in,line)){
        sb.push_back(line);
    }

    //StrBlobPtr start(sb.begin());
    //StrBlobPtr end(sb.end());
    //for(;start != end; start.incr())
    for(StrBlobPtr pstart(sb.begin()),pend(sb.end());pstart != pend; pstart.incr())
        std::cout << pstart.deref() << endl;
    cout << endl;
}
