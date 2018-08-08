class Base{
    public:
        void pub_mem();
    protected:
        int prot_mem;
    private:
        int priv_mem;
};

struct Pub_Derv : public Base {
    void memfunc(Base &b){ b = *this; }
};
struct Prot_Derv : protected Base {
    void memfunc(Base &b){ b = *this; }
};

struct Priv_Derv : private Base {
    void memfunc(Base &b){ b = *this; }
};

struct Derv_from_Pub : public Pub_Derv {
    void memfunc(Base &b)
    {
        b = *this;
    }
};
struct Derv_from_Priv : private Priv_Derv {
//    void memfunc(Base &b) { b = *this;}
};
struct Derv_from_Prot : protected Prot_Derv {
    void memfunc(Base &b)
    {
        b = *this;
    }
};

int main(){
    Pub_Derv d1;
    Base * p = &d1;

    Priv_Derv d2;
//    p = &d2;

    Prot_Derv d3;
//    p = &d3;

    Derv_from_Pub dd1;
    p = &dd1;

    Derv_from_Priv dd2;
//    p = &dd2;

    Derv_from_Prot dd3;
 //   p = &dd3;

    return 0;
}
