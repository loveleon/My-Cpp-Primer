#include <utility>
#include <string>

class Sharp {
    public:
        typedef std::pair<double,double> Cordinate;
        Sharp() = default;
        Sharp(const std::string &_name):name(_name){}
        virtual double area() = 0;
        virtual double peremeter() = 0;
        virtual ~Sharp() = default;
    private:
        std::string name;
};

class Rectangle : public Sharp {
    public:
        Rectangle() = default;
        Rectangle(const std::string& _name,
                const Cordinate& _a,
                const Cordinate& _b,
                const Cordinate& _c,
                const Cordinate& _d):Sharp(_name),a(_a),b(_b),c(_c),d(_d){}
        virtual ~Rectangle() override = default;
        virtual double area() override{return 0.0f;}
        virtual double peremeter() override{return 0.0f;}
    protected:
        Cordinate a;
        Cordinate b;
        Cordinate c;
        Cordinate d;
};

class Square : public Rectangle{
    public:
        Square() = default;
        Square(const std::string& _name,
                const Cordinate& _a,
                const Cordinate& _b,
                const Cordinate& _c,
                const Cordinate& _d):Rectangle(_name,_a,_b,_c,_d){}
        virtual ~Square() = default;
};

int main(){
    Square sq;
    Sharp& sp = sq;
    sp.area();
    return 0;
}
