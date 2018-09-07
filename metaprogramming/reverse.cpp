#include <iostream>


template<long long N>
struct len
{
    enum  { value = 1 + len<N/10>::value };
};

template<>
struct len<0>
{
    enum { value = 0 };
};

template<int N>
struct pow
{
    enum { value = 10 * pow<N-1>::value };
};

template<>
struct pow<0>
{
    enum { value = 1} ;
};


template<long long N, int l = len<N>::value - 1>
struct reverse
{
    enum { value = N % 10 * pow<l>::value + reverse<N/10>::value };
};

template<>
struct reverse<0>
{
    enum { value = 0 };
};

int main()
{
    std::cout << reverse<432452>::value << std::endl;
    return 0;
}
