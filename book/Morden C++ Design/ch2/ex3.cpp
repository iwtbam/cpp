//函数模板只能全特化，不能偏特化

#include <iostream>

template<typename T>
T func(T t)
{
    return t;
}

template<>
int func<int>(int i)
{
    return i+1;
}


template<typename T1, typename T2>
auto add(T1 v1, T2 v2) -> decltype(v1+v2)
{
    return v1 + v2;
}

template<>
int add<int, int>(int v1, int v2)
{
    return v1 + v2;
}

// 编译错误：non-class, non-variable, paritial specialization 'add<T, T>' is not allowed
// template<typename T>
// T add<T, T>(T v1, T v2)
// {
//     return v1 + v2;
// }

//函数模板缺少偏特化的机制，利用重载机制， 实现函数接口的统一
template<typename T>
struct Type2Type
{
    using value_type = T;
};

template<typename T, typename U>
int getValue(T t, Type2Type<U>())
{
    return 1;
}

template<typename T>
int getValue(T t, Type2Type<int>())
{
    return 2;
}



int main()
{
    char i = 5;
    char ii = func(i);
    std::cout<<int(ii)<<std::endl;
    return 0;
}