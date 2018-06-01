#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
using std::ifstream;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::cout;
using std::endl;
using std::cin;

int main(){
    ifstream in("../ex10_33_input.txt",in.in);
    ofstream out1("ex10_33_out1",out1.out|out1.app);
    ofstream out2("ex10_33_out2",out2.out|out2.app);
    istream_iterator<int> itin(in),itineof;
    ostream_iterator<int> itout1(out1," ");
    ostream_iterator<int> itout2(out2,"\n");
//    std::copy_if(itin,itineof,itout2,[](const int &i){return i%2 == 1;});
 //   std::copy_if(itin,itineof,itout1,[](const int &i){return i%2 == 0;});
    //in.clear();
    //std::copy_if(itin,itineof,itout2,[](const int &i){return i%2 == 0;});

    for_each(itin,itineof,[&itout1,&itout2](const int &i){
            *(i%2 == 0? itout1:itout2)++ = i;
            });

    return 0;
}
