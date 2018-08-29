#pragma once
#include <memory>
#include <vector>
#include <string>
using std::vector;
using std::shared_ptr;
using std::string;

template<typename T>
class Blob{
    public:
       typedef T value_type;
       typedef typename vector<T>::size_type size_type;

       //constructor
       Blob();
       Blob(std::initializer_list<T> nil);

       //number of element in the Blob
       size_type size()const {return data->size();}
       bool empty()const {return data->empty();}

       void push_back(const T& t){data->push_back(t);}
       void push_back(T&& t){data->push_back(std::move(t));}
       void pop_back();

       T& back();
       T& operator[](size_type i);

       const T& back()const;
       const T& operator[](size_type i)const;

    private:
    std::shared_ptr<vector<T>> data;
    void check(size_type i,const string& msg)const;
};

template<typename T>
Blob<T>::Blob():data(std::make_shared<vector<T>>())
{
}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> nil):data(std::make_shared<vector<T>>(nil))
{
}

template<typename T>
T& Blob<T>::back()
{
    check(0,"back on empty Blob");
    return (*data).back();
}

template<typename T>
const T& Blob<T>::back()const{
    check(0,"back on empty Blob");
    return data->back();
}

template<typename T>
void Blob<T>::check(size_type i ,const string& msg)const
{
    if(i>= data->size())
        throw std::out_of_range(msg);
}

template<typename T>
T& Blob<T>::operator[](size_type i){
    check(i,"subscribe out of range.");
    return data->at(i);
}

template<typename T>
const T& Blob<T>::operator[](size_type i)const{
    check(i,"subscribe out of range.");
    return data->at(i);
}

template<typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

