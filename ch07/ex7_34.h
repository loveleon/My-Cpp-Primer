#ifndef _EX7_23_H__
#define _EX7_23_H__
#include <iostream>
#include <string>
#include <vector>
using std::string;

class Screen;
class Window_mgr{
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
    public:
        void clear(ScreenIndex i);
    private:
        std::vector<Screen> screens ;
        //std::vector<Screen&> screens ;
};

class Screen{
    public:
        typedef std::string::size_type pos;
    friend void Window_mgr::clear(pos ScreenIndex);
    private:
        pos width = 0,height=0;
        pos cursor = 0;
        std::string content;
    private:
        void do_display(std::ostream& out) const{
           out << content;
        }
    public:
        pos size()const;
        Screen set(char c){
            content[cursor] = c;
            return *this;
        };
        Screen display(std::ostream& out);
        const Screen& display(std::ostream& out)const;
        Screen() = default;
        Screen(const pos w, const pos h):width(w),height(h),content(w*h,' '){}
        Screen(const pos w,const pos h, char c):width(w),height(h),content(string(w*h,c)){}
        inline char get(pos r, pos c)const;
        char get()const{
            return content[cursor];
        }
        Screen move(pos r,pos c);
};

void Window_mgr::clear(ScreenIndex i){
    Screen& s = screens[i];
    s.content = string(s.width*s.height,' ');
}

Screen::pos Screen::size()const{
    return width*height;
}

Screen Screen::display(std::ostream& out){
    do_display(out);
    return *this;
}

const Screen& Screen::display(std::ostream& out)const{
    do_display(out);
    return *this;
}

Screen Screen::move(pos r, pos c){
    pos row = r * width;
    cursor = row + c;
    return *this;
}

char Screen::get(pos r, pos c) const{
    pos row = r*width;
    return content[row+c];
}
#endif


