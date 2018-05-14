#ifndef _EX8_01_H__
#define  _EX8_01_H__
#include <iostream>
#include <string>
using std::string;
std::istream& read(std::istream& in){
    string tmp;
    while(in >> tmp){
//            std::cout << std::boolalpha ;
        std::cout << tmp << std::endl;
    }
    std::cout << "done" << std::endl;

    in.clear(in.rdstate() & ~in.eofbit);
    std::cout <<std::boolalpha <<  in.eofbit << std::endl;
    std::cout << std::boolalpha  << in.goodbit <<std::endl;
    std::cout << std::boolalpha  <<in.failbit << std::endl;

    in.clear();


    return in;
}
#endif
