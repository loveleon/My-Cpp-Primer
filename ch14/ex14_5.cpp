//
// Created by cxh on 18-7-17.
//
#include "ex14_5.h"
Book::Book(std::istream &is){
    is >> *this;
}

std::ostream& operator<<(std::ostream& out,const Book & book){
    out << book.no_ << " " << book.name_<< " " << book.autor_ << " " << book.pubdate_;
    return out;
}

std::istream& operator>>(std::istream& in, Book &book){
    in >> book.no_ >> book.name_  >> book.autor_ >> book.pubdate_;
    return in;
}

bool operator==(const Book &lft, const Book &rhs){
    return lft.no_ ==  rhs.no_ && lft.name_ == rhs.name_ && lft.autor_ == rhs.autor_ && lft.pubdate_ == rhs.pubdate_;
}

bool operator!=(const Book &lft, const Book &rhs){
    return !(lft == rhs);
}

