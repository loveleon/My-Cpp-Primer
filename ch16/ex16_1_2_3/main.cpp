//
//
//ex16.1
//��������ʵ����һ��ģ��ʱ������ʹ��ʵ�ʵ�ģ�������s����������Ӧ��ģ�������s��������ģ����¡�ʵ����.

//ex16.2
#include <iostream>
#include <vector>
#include <list>
class Sales_data{
    public:
        friend bool operator<(Sales_data& s1,Sales_data& s2){return true;}
        friend bool operator>(Sales_data& s1,Sales_data& s2){return false;}
};

template<typename T>
int compare(T& l, T& r)
{
    if(l<r)
        return -1;
    if(l>r)
        return 1;
    return 0;
}

int main(){
    Sales_data s1,s2;
    std::vector<int> v1={1,2,3},v2={1,2,2};
    std::list<int> l1={2,3,4},l2={2,3,3};
    std::cout << "Sales_data compare :" << compare<Sales_data>(s1,s2)<< std::endl;
    std::cout << "Vector compare :" << compare<std::vector<int>>(v1,v2) << std::endl;
    std::cout << "List compare :" << compare(l1,l2) << std::endl;

    return 0;
}
