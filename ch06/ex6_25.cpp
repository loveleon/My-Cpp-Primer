#include "comm/comm.h"

int main(int argc,char**argv){
    if(argc < 3){
        return 1;
    }else{
        string str = string(argv[1])+string(argv[2]);
        cout << str <<endl;
    }
}
