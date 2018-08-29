//16.9
//function template is type-specific version of that function.
//class template is different to function template because compiler can't deduce the template parameter type.
//when new a instance with class template,we should supply the type parameter.
//
//16.10
//compiler will use the template parameter to instantiate the specific class from template class.
//
//16.11
template<typename elemType> class ListItem;
template<typename elemType> class List{
    public:
        List<elemType>();
        List<elemType>(const List<elemType>&);
        List& operator=(const List<elemType>&);
        ~List();
        void insert(ListItem<elemType> *ptr,elemType value);
    private:
        ListItem<elemType> *front,*end;
};
