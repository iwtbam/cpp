#include <iostream>

template<int v>
struct Int2Type
{
    enum { value = v};
};



//编译器不会编译一个未被用的 template 函数


//在编译器阶段实现一个分派

struct A
{
    char getA(){ return 'A'; }
};

struct B
{
    char getB(){ return 'B'; }
};

template<class T, int v>
struct C
{
private:
    char getC(T t ,Int2Type<1>)
    {
        return t.getA();
    }

    char getC(T t, Int2Type<2>)
    {
        return t.getB();
    }

public:

    char getC(T t)
    {
        getC(t, Int2Type<v>());
    }
};

int main()
{
    C<A,1> c1;
    std::cout<< c1.getC(A()) <<std::endl;
    C<B,2> c2;
    std::cout<< c2.getC(B()) <<std::endl;
    return 0;
}