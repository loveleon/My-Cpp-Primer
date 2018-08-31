//16.17 当声明类型参数是，typename同class.
//当通知编译器名称表示类型时候，必须用typename
//
//16.18
//(a)template <typename T,typename U,typename V> void f1(T,U,V)
//(b)template<typename T> T f2(T& t)
//(c)template <typename T> inline T foo(T,unsigned int * );
//(d)template <typename T> void f4(T,T);
//(e)typedef char Ctype;
//    template <typename Ctype> Ctype f5(Ctype a);//template Ctype HIDE the typedef Ctype.
