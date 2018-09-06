//ex16.32
//during template prameter deduction ,compiler use types of the argument in the call to find the template
//arguments that generate a version of the function that best matches the given call.
//
//ex16.33
//transfer to const parameter and array address transfer to pointer.(array could not be reference).
//
//ex16.34
//template <class T> int compare(const T&,const T&);
//(a)compare("hi","world");(b)compare("bye","dad");
//(a)compile error.T1 is char[3],T2 is char[6]
//(b)T is char*
//
//ex16.35
//template <typename T> T calc(T,int);
//template <typename T> T fcn(T,T);
//double d;float f;char c;
//(a)calc(c,'c'); legal T is char
//(b)calc(d,f); legal T is double
//(c)fcn(c,'c');legal T is char
//(d)fcn(d,f);illlegal
//
//ex16.36
//template <typename T> f1(T,T);
//template <typename T1,typename T2> f2(T1,T2);
//int i = 0,j=42;*p1=&i,*p2=&j;
//const int *cp1 =&i,*cp2=&j;
//(a)f1(p1,p2) f1<int*,int*>
//(b)f2(p1,p2) f2<int*,int*>
//(c)f1(cp1,cp2) f1<int const *>(int const*,int const*);
//(d)f2(cp1,cp2) f2<int const *>(int const *,int const *);
//(e)f1(p1,cp1) deduced conflicting types for parameter 'T'
//(f)f2(p1,cp1) f2<int *,int const *>(int *,int const *);
