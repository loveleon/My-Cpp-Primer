#include "ex12_02.h"
#include <exception>
void StrBlob::check(size_type sz,string str)const{
    if(sz > size()){
        throw std::out_of_range(str);
    }
}

const string& StrBlob::front()const{
    check(0,"empty of front.(const)");
    return data->front();
}

string& StrBlob::front(){
    check(0,"empty of front.");
    return data->front();
}

string& StrBlob::back(){
    check(0,"empty of back");
    return data->back();
}

const string& StrBlob::back()const{
    check(0,"empty of back(const)");
    return data->back();
}

void StrBlob::push_back(string str){
    data->push_back(str);
}

void StrBlob::pop_back(){
    if(!empty())
        data->pop_back();
}

int main(){
    const StrBlob csb = {"cxh","awe","adf"};
    StrBlob sb = {"cxh","awe","awk"};
    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.front() = "tiger";
    std::cout << sb.front() << " " << sb.back() << std::endl;
    return 0;
}
