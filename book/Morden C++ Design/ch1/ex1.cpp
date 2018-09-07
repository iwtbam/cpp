//Morden C++ Design P7 一些问题实践 

#include <iostream>


template<typename T>
class Test
{
public:
    T value;
    void Func();
};

// 可以特化成员函数法特化数据成员
template<typename T>
void Test<T>::Func()
{

};

template<> 
void Test<char>::Func()
{
    std::cout<<"char"<<std::endl;
};

template<>
void Test<int>::Func()
{
    std::cout<<"int"<<std::endl;
};

//多参数模板，成员函数不支持偏特化机制
template<typename T, typename U>
struct Test2
{
    void Func();
};

template<typename T, typename U>
void Test2<T,U>::Func()
{

}

template<>
void Test2<char,char>::Func()
{
    std::cout<<"char,char"<<std::endl;
}

template<>
void Test2<char,int>::Func()
{
    std::cout<<"char,int"<<std::endl;
}

// template<typename U>
// void Test2<char,U>::Func()
// {

// }
// 报错 
int main()
{
    Test<char> t1;
    Test<int> t2;
    t1.Func();
    t2.Func();
    Test2<char,char> t3;
    Test2<char,int> t4;
    t3.Func();
    t4.Func();
    return 0;
}