//ex16.42
//template<typename T> void g(T&& val)
//int i=0;const int ci = i;
//(a)g(i) T=int& val=lvalue  i is lvalue ,T is deduced as int&,val is int& && collapsing to int&
//(b)g(ci) error:(T=int val=rvalue) ci is lvale,T is deduced as const int&,val is const int& && collapsing to const int&
//(c)g(i*ci)T=int val=rvalue i*ci is rvalue ,T is deduced as int&& ,val is int&& && collapsing to int&&.
//
//ex16.43
//(i=ci) return lvalue refering to the i,Hence T is int& val is int& &&.any change on val changes the i.
//
//ex16.44
//g(T val)
//(a)g(i) i is lvalue, T is int, val is int.
//(b)g(ci)ci is lvalue, T is  int, const is ignored.
//(c)g(i*ci) i*ci is rvalue which is coped to T, T is int,val is int.
//
//g(const T&)
//(a)g(i) i is lvalue, T is int, val is const int&
//(b)g(ci) ci is lvalue, T is const int ,val is const const int& collapsing to const int&.
//(c)g(i*ci) i*ci is rvalue, T is int,val is const int&
//
//ex16.45
//template<typename T> void g(T&& val){vector<T> v;}
//g(42) val is 42(rvalue), int&& && is collapsing to int&& ,at last T deduced as int.Hence std::vector<T> is instantiated as
//std::vector<int> which is legal.
//g(int) val is lvalue, T deduced as int&,int& && is collapsing to int&.std::vector<int &> is legal.(The component type of containers like vectors must be assignable. vector<const int> also illlegal)
//https://stackoverflow.com/questions/922360/why-cant-i-make-a-vector-of-references
//https://stackoverflow.com/questions/21624016/when-a-lvalue-is-passed-to-t-what-will-happen
//
//ex16.46
//in each iteration,the dereference operator * is returned lvalue which is changed to rvalue by std::move.Because construct takes
//rvalue reference rather than lvalue reference.
