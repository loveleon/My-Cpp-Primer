//
// Created by cxh on 18-5-10.
//
#include <iostream>
#include <string>
#include <type_traits>
struct Data{
    int ival;
    std::string s;
};

int main(int argc,char *argv[]){
    std::cout << std::boolalpha ;
    std::cout << std::is_literal_type<Data>::value << std::endl;

    return 0;
}
