#include "comm/comm.h"

void print(const int i[],int size){
    for(int index=0;index < size;index++){
        cout << i[index] << " ";
    }
    cout << endl;
}
/*
void print(const int (&i)[2]){
    for(auto it : i)
        cout << it << " ";
    cout << endl;
}//*/

void print(const int* i){
    cout << *i << endl;
}//*/

void print(const char* p){
    if(p){
        while(*p){
            cout << *p++ << " ";
        }
        cout <<endl;
    }
}

void print(const int (&ia)[2]){
    for(size_t i=0;i != 2;i++)
        cout <<ia[i] << " ";
    cout << endl;
}

int main(){
    int i=2,j[]={1,2};
    char p[] = "12345\0";
    print(j);
    print(&i);
    print(j,sizeof(j)/sizeof(int));
    print(p);

    return 0;
}
