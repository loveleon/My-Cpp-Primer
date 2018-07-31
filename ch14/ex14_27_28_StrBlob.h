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

bool operator==(const StrBlobPtr &,const StrBlobPtr &);
bool operator!=(const StrBlobPtr &,const StrBlobPtr &);
bool operator<(const StrBlobPtr &,const StrBlobPtr &);
bool operator<=(const StrBlobPtr &,const StrBlobPtr &);
bool operator>(const StrBlobPtr &,const StrBlobPtr &);
bool operator>=(const StrBlobPtr &,const StrBlobPtr &);

inline string& StrBlobPtr::deref()const
{
    auto sp = check(curr,"out of range.");
    return (*sp)[curr];
}

inline StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr,"out of range.");
    ++curr;
    return *this;
}

inline StrBlobPtr& StrBlobPtr::operator--()
{
    check(--curr,"out of range.");
    return *this;
}

inline StrBlobPtr StrBlobPtr::operator++(int)
{
    //check(curr,"out of range.");
    //auto ret = *this;
    //++curr;
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

inline StrBlobPtr StrBlobPtr::operator--(int)
{
    auto ret = *this;
    --*this;
    return ret;
}

inline StrBlobPtr& StrBlobPtr::operator+=(size_t n)
{
    curr += n;
    check(curr,"out of range.");
    return *this;
}

inline StrBlobPtr& StrBlobPtr::operator-=(size_t n)
{
    curr -= n;
    check(curr, "out of range.");
    return *this;
}

inline StrBlobPtr StrBlobPtr::operator+(size_t n)
{
    StrBlobPtr ret = *this;
    ret += n;
    return ret;
}

inline StrBlobPtr StrBlobPtr::operator-(size_t n)
{
    StrBlobPtr ret = *this;
    ret -= n;
    return ret;
}

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t n, const string &msg) const
{
    auto ret = wptr.lock();
    if(!ret) throw std::runtime_error("unbound .");
    if(n >= ret->size()) throw std::out_of_range(msg);
    return ret;
}

inline string& StrBlobPtr::operator[](const size_t n)
{
    auto sp = check(n,"out of range.");
    return (*sp)[n];
}

inline const string& StrBlobPtr::operator[](const size_t n)const
{
    auto sp = check(n,"out of range.");
    return (*sp)[n];
}


//ConstStrBlobPtr custom const iterator of StrBlob
class ConstStrBlobPtr{
    friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator< (const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator> (const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    public:
        ConstStrBlobPtr():curr(0){}
        ConstStrBlobPtr(const StrBlob &sb, size_t sz=0):wptr(sb.data),curr(sz){}

        const string& deref()const;
        ConstStrBlobPtr& operator++();
        ConstStrBlobPtr& operator--();
        ConstStrBlobPtr operator++(int);
        ConstStrBlobPtr operator--(int);
        ConstStrBlobPtr& operator+=(size_t);
        ConstStrBlobPtr& operator-=(size_t);

        ConstStrBlobPtr operator+(size_t )const;
        ConstStrBlobPtr operator-(size_t )const;

        const string& operator[](size_t)const;
        string& operator[](size_t);
    private:
        shared_ptr<vector<string>> check(size_t,const string&)const;
        std::weak_ptr<vector<string>> wptr;
        size_t curr;
};
bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator< (const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator> (const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

inline const string& ConstStrBlobPtr::deref()const
{
    auto sp = check(curr,"out of range.");
    return (*sp)[curr];
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator++()
{
    check(curr,"out of range.");
    ++curr;
    return *this;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator--()
{//check(-1,"out of range.");
    check(--curr,"out of range.");
    return *this;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator++(int)
{
    ConstStrBlobPtr ret = *this;
    ++*this;
    return ret;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator--(int)
{
    ConstStrBlobPtr ret = *this;
    --*this;
    return ret;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator+=(size_t n)
{
    curr += n;
    check(n,"out of range.");
    return *this;
}

inline ConstStrBlobPtr& ConstStrBlobPtr::operator-=(size_t n)
{
    curr -= n;
    check(curr,"out of range.");
    return *this;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator+(size_t n)const
{
    ConstStrBlobPtr ret = *this;
    ret += n;
    return ret;
}

inline ConstStrBlobPtr ConstStrBlobPtr::operator-(size_t n)const
{
    ConstStrBlobPtr ret = *this;
    ret -= n;
    return ret;
}

inline shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t n, const string &msg)const
{
    auto ret = wptr.lock();
    if(!ret)
        throw std::runtime_error("unbound element.");
    if(n >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

inline const string& ConstStrBlobPtr::operator[](size_t n)const
{
    auto sp = check(n,"out of range.");
    return (*sp)[n];
}

