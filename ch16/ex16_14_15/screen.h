#pragma once
#include <iostream>
#include <string>

template<unsigned h,unsigned w>
class Screen {
    public:
        typedef std::string::size_type pos;

        Screen() = default;
        Screen(char c):contents(h*w,c){}

        Screen& move(pos r, pos c);

        char get()const
        {
            return contents[cursor];
        }
        friend std::ostream& operator<<(std::ostream& out, const Screen<h,w>& s)
        {
            int i;
            for(i =0;i<s.heigh;++i)
                out << s.contents.substr(0,w) << std::endl;
            return out;
        }

        friend std::istream& operator>>(std::istream& in, Screen<h,w>& s)
        {
            char c;
            in >> c;
            std::string temp(h*w,c);
            s.contents = temp;
            return in;
        }

    private:
        pos heigh = h,wide = w;
        pos cursor = 0;
        std::string contents;

};

template <unsigned h, unsigned w> std::ostream& operator<<(std::ostream& ,const Screen<h,w>& );

template<unsigned h,unsigned w>
Screen<h,w>& Screen<h,w>::move(pos r, pos c)
{
    pos row = r*wide;
    cursor = row + c;
    return *this;
}
