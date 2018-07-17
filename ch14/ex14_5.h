//
// Created by cxh on 18-7-17.
//

#ifndef MY_CPP_PRIMER_EX14_5_H
#define MY_CPP_PRIMER_EX14_5_H
#include <string>

class Book{
    public:
        friend std::ostream& operator<<(std::ostream& out,const Book & book);
        friend std::istream& operator>>(std::istream& in, Book &book);

    public:
        Book(std::string name,std::string autor, std::string pubdate):name_(name),autor_(autor),pubdate_(pubdate){}
private:
    std::string name_;
    std::string autor_;
    std::string pubdate_;
};
#endif //MY_CPP_PRIMER_EX14_5_H
