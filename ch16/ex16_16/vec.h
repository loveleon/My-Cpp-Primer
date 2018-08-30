#pragma once
#include <memory>

/*
 * @brief a vector like a class.
 */
template <typename T>
class Vec{
    public:
        Vec():element(nullptr),first_free(nullptr),cap(nullptr){}
        //Vec() = default;
        Vec(std::initializer_list<T> nil);
        Vec(const Vec& v);
        Vec& operator=(const Vec& v);
        ~Vec();

        std::size_t size() const{return first_free - element;}
        std::size_t capacity() const { return cap - element; }

        void push_back(const T& t);
        T* begin()const{return element;}
        T* end()const{return first_free;}

        void reserve(std::size_t n);
        void resize(std::size_t n);
        void resize(std::size_t n,const T& t);

    private:
        T* element;
        T* first_free;
        T* cap;

        std::allocator<T> alloc;

        //utilities
        void reallocate();
        void chk_n_alloc() {
            if(size() == capacity())
                reallocate();
        }
        void free();

        void wy_alloc_n_move(std::size_t n);

        std::pair<T*,T*> alloc_n_copy(T* b, T* e);
};

//copy constructor
template<typename T>
Vec<T>::Vec(const Vec& v){
    /**
     * @brief newData is a pair of pointers pointing to newly allocated and copied
     *        from range : [b, e)
     */
    auto newdata = alloc_n_copy(v.begin(),v.end());
    element = newdata.first;
    first_free = cap = newdata.second;
}

template<typename T>
Vec<T>::Vec(std::initializer_list<T> nil)
{
    //allocate nil.size() memory for constructor.
    T* const newdata = alloc.allocate(nil.size());

    T* p = newdata;
    for(const auto& it : nil)
    {
        alloc.construct(p++,it);
    }

    element = newdata;
    //first_free = cap = p;
    first_free = cap = element + nil.size();
}

template<typename T>
Vec<T>& Vec<T>::operator=(const Vec& v)
{
//    if(*this != v)//because copy vec into temp vec.so NOT need to 'if' condition.
//    {
        std::pair<T*,T*> newdata = alloc_n_copy(v.begin(),v.end());
        free();
        element = newdata.first;
        first_free = cap = newdata.second;
//    }
    return *this;
}

template<typename T>
Vec<T>::~Vec()
{
    free();
}

/**
 * @brief   allocate new memeory if nessary and push back the new T
 * @param t new T
 */
template<typename T>
void Vec<T>::push_back(const T& t)
{
    chk_n_alloc();
    alloc.construct(first_free++,t);
}


/**
 * @brief   preallocate enough memory for specified number of elements
 * @param n number of elements required
 */
template<typename T>
void Vec<T>::reserve(std::size_t n )
{
    if(n<capacity())
        return;
    wy_alloc_n_move(n);
}


/**
 *  @brief  Resizes to the specified number of elements.
 *  @param  n  Number of elements the %vector should contain.
 *
 *  This function will resize it to the specified
 *  number of elements.  If the number is smaller than the
 *  current size it is truncated, otherwise
 *  default constructed elements are appended.
 */
template<typename T>
void Vec<T>::resize(std::size_t n )
{
    resize(n,T());
}

template<typename T>
void Vec<T>::resize(std::size_t n, const T& t)
{
    if(n < size())
    {
        for(auto it = element + n; it != first_free; )
            alloc.destroy(it++);
        first_free = element + n;
    }
    else if(n > size())
    {
        for(auto it = size();it != n;++it)
            push_back(t);
    }
}

/**
 * @brief   allocate new space for the given range and copy them into it
 * @param b
 * @param e
 * @return  a pair of pointers pointing to [first element , one past the last) in the new space
 */
template<typename T>
std::pair<T*,T*> Vec<T>::alloc_n_copy(T* b,T* e)
{
    T* newdata = alloc.allocate(e-b);
    return {newdata,std::uninitialized_copy(b,e,newdata)};
}


/**
 * @brief   destroy the elements and deallocate the space previously allocated.
 */
template<typename T>
void Vec<T>::free()
{
    if(element)
    {
        for(auto it=first_free; it != element; )
            alloc.destroy(--it);

        alloc.deallocate(element,capacity());
    }
}


/**
 * @brief   allocate memory for spicified number of elements
 * @param n
 * @note    it's user's responsibility to ensure that @param n is greater than
 *          the current capacity.
 */
template<typename T>
void Vec<T>::wy_alloc_n_move(std::size_t n)
{
    //allocate the required capacity.
    std::size_t newCap = n;
    T* newdata = alloc.allocate(newCap);

    //move data from old place to new place.
    T* dest = newdata;
    T* old = element;
    for(std::size_t i = 0; i != size();++i)
        alloc.construct(dest++,std::move(*old++));

    //free old data allocate.
    free();

    element = newdata;
    first_free = dest;
    cap = element + newCap;
}

/**
 * @brief   Double the capacity and using std::move move the original data to the newly
 *          allocated memory
 */
template<typename T>
void Vec<T>::reallocate()
{
    auto newCap = size()?size()*2:1;
    wy_alloc_n_move(newCap);
}
