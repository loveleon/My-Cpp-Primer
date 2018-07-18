//
// Created by cxh on 18-7-17.
//

#ifndef MY_CPP_PRIMER_EX14_5_H
#define MY_CPP_PRIMER_EX14_5_H
#include <string>
#include <iostream>

class Book{
    public:
        friend std::ostream& operator<<(std::ostream& out,const Book & book);
        friend std::istream& operator>>(std::istream& in, Book &book);
        friend bool operator==(const Book &lft, const Book &rhs);
        friend bool operator!=(const Book &lft, const Book &rhs);
    public:
        Book() = default;
        Book(unsigned no,std::string name,std::string autor, std::string pubdate):no_(no),name_(name),autor_(autor),pubdate_(pubdate){}
        Book(std::istream &is);
private:
    unsigned no_;
    std::string name_;
    std::string autor_;
    std::string pubdate_;
};
    std::ostream& operator<<(std::ostream& out,const Book & book);
    std::istream& operator>>(std::istream& in, Book &book);
    bool operator==(const Book &lft, const Book &rhs);
    bool operator!=(const Book &lft, const Book &rhs);
#endif //MY_CPP_PRIMER_EX14_5_H
