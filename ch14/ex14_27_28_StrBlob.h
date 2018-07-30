#pragma once

#include <vector>
#include <initializer_list>
#include <memory>
#include <exception>
#include <string>

using std::initializer_list;
using std::vector;
using std::shared_ptr;
using std::string;
using std::make_shared;


class StrBlobPtr;
class ConstStrBlobPtr;

//custom vector<string>
class StrBlob{
    using size_type=vector<string>::size_type;
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);
    friend bool operator<(const StrBlob &, const StrBlob &);
    friend bool operator<=(const StrBlob &, const StrBlob &);
    friend bool operator>(const StrBlob &, const StrBlob &);
    friend bool operator>=(const StrBlob &, const StrBlob &);

    public:
        StrBlob():data(make_shared<vector<string>>()){}
        StrBlob(const StrBlob &sb):data(make_shared<vector<string>>(*sb.data)){}
        StrBlob &operator=(const StrBlob &);
        StrBlob(initializer_list<string> *il):data(make_shared<vector<string>>(il)){}

        StrBlob(StrBlob &&rhs):data(std::move(rhs.data)){}
        StrBlob &&operator=(StrBlob &&rhs)noexcept;

        StrBlobPtr begin();
        StrBlobPtr end();

        ConstStrBlobPtr begin()const;
        ConstStrBlobPtr end()const;

        string& operator[](size_t n);//{return data->at(n);}
        const string& operator[](size_t n)const;

        size_t size(){return data->size();}
        bool empty()const{return data->empty();}

        void push_back(const string &s){data->push_back(s);}
        void push_back(string &&s){return data->push_back(std::move(s));}

        void pop_back();
        string& front();
        string& back();
        const string& front()const;
        const string& back()const;
    private:
        void check(size_type ,const string &)const;
        shared_ptr<vector<string>> data;
};

bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);

inline void StrBlob::pop_back(){
    check(0,"pop_back on empty vector.");
    data->pop_back();
}

inline string& StrBlob::front()
{
    check(0,"front on empty vector.");
    return data->front();
}

inline string& StrBlob::back()
{
    check(0,"back on empty vector.");
    return data->back();
}

inline const string& StrBlob::front()const
{
    check(0,"front on empty vector.");
    return data->front();
}

inline const string& StrBlob::back()const
{
    check(0,"back on empty vector.");
    return data->back();
}


inline void StrBlob::check(size_t i, const string &msg)const
{
    if(i>=data->size())
        throw std::out_of_range(msg);
}

inline string& StrBlob::operator[](size_t n)
{
    check(n,"out of range.");
    return data->at(n);
}

inline const string& StrBlob::operator[](size_t n)const
{
    check(0,"out of range");
    return data->at(n);
}

//StrBlobPrt custom iterator of StrBlob
class StrBlobPtr{
    friend bool operator==(const StrBlobPtr &,const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &,const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &,const StrBlobPtr &);
    friend bool operator<=(const StrBlobPtr &,const StrBlobPtr &);
    friend bool operator>(const StrBlobPtr &,const StrBlobPtr &);
    friend bool operator>=(const StrBlobPtr &,const StrBlobPtr &);
    public:
        StrBlobPtr():curr(0){}
        StrBlobPtr(StrBlob& sb, size_t sz=0):wptr(sb.data),curr(sz){}

        string& deref()const;
        StrBlobPtr& operator++();
        StrBlobPtr& operator--();
        StrBlobPtr operator++(int);
        StrBlobPtr operator--(int);
        StrBlobPtr& operator+=(size_t);
        StrBlobPtr& operator-=(size_t);
        StrBlobPtr operator+(size_t);
        StrBlobPtr operator-(size_t);

        string& operator[](size_t n);
        const string& operator[](size_t n)const;
private:
    shared_ptr<vector<string>> check(size_t,const string &)const;

    std::weak_ptr<vector<string>> wptr;
    size_t curr;


};
