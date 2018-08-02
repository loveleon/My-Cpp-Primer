#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
class Equal{
    private:
        int i;
    public:
        Equal(int i_=0):i(i_){}
        bool operator()(int num){
            return num == i;
        }
};

int main(){
    vector<int> vec{1,2,3,4,3,5,6,3,7,8};
    std::replace_if(vec.begin(),vec.end(),Equal(3),11);
    std::for_each(vec.begin(),vec.end(),[](const int& i){ std::cout << i << " "; });
    std::cout << std::endl;
    return 0;
}
