//
// Created by cxh on 18-5-10.
//

#ifndef CH06_EX7_53_H
#define CH06_EX7_53_H
class Debug{
public:
    constexpr Debug(booL b = true):hw(b),io(b),other(b){}
    constexpr Debug(bool hw_,bool io_,bool other_):hw(hw_),io(io_),other(other_){}
    constexpr any(){return hw || io || other;}
    void set_io(bool b){
        io = b;
    }
    void set_hw(bool b){hw = b;}
    void set_other(bool b){other = b;}

private:
    bool hw;
    bool io;
    bool other;
};
#endif //CH06_EX7_53_H
