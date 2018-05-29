#include "common.h"

struct Sales_data{
    string bookNo;
    string isbn()const {return bookNo;}
    Sales_data(string str):bookNo(str){}
};

void print(vector<Sales_data > &vec){
    for(const auto s : vec){
        cout << s.bookNo << " ";
    }
    cout << endl;
}
bool compareisbn(const Sales_data & s1, const Sales_data &s2){
    //if(s1.isbn() < s2.isbn()){
    if(s1.isbn().size() < s2.isbn().size()){
        return true;
    }else{
        return false;
    }
}


int main(){
    //vector<Sales_data &> vec = {Sales_data("xxx-zzz-yyy"),Sales_data("xxx-yyy-zzz"),Sales_data("zzz-zzz-yyy"),Sales_data("zzz-yyy-yyy"),Sales_data("zzz-xxx-yyy"),Sales_data("www-yyy-xxx"),Sales_data("www-xxx-yyy")};
    Sales_data d1{"xx-zzz-yyy"},d2{"xxx-yyy-zzz"},d3{"zzz-zzz-yyy"},d4{"zzz-yyy-yyy"},d5{"zzz-xxx-yyy"},d6{"www-yyy-xxx"},d7{"www-xxx-yyy"};
    vector<Sales_data> vec = {d1,d2,d3,d4,d5,d6,d7};
    std::sort(vec.begin(),vec.end(),compareisbn);
    /*
    std::sort(vec.begin(),vec.end(),[](const Sales_data &s1, const Sales_data &s2)->bool{
            if(s1.isbn().size() < s2.isbn().size())
                return true;
                else
                return false;
                });*/
//    std::stable_sort(vec.begin(),vec.end(),compareisbn);
    for(const auto &s : vec){
        cout << s.bookNo << " ";
    }
    cout << endl;

    return 0;
}
