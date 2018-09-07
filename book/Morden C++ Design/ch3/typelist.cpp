#include <iostream>
#include <typeinfo>

template<typename... Args> struct typelist {};

template<>
struct typelist<>{};

template<int i, typename T> struct at;

template<int i, typename T, typename... Args>
struct at<i, typelist<T, Args...>>:
    at<i-1, typelist<Args...>>
    {};

template<typename T, typename... Args>
struct at<0, typelist<T, Args...>>
{
    using type = T;
};

template<int i>
struct at<i, typelist<>>
{
    using type = typelist<>;
    static_assert(i>0,  "index out of range");
};

template<typename T, typename U> struct index;

template<typename T, typename U, typename... Args>
struct index<T, typelist<U, Args...>>
{
    enum { value = index<T,typelist<Args...>>::value } ;
};

template<typename T>
struct index<T, typelist<>>
{
    enum { value = 0 };
};

template<typename T, typename... Args> 
struct index<T, typelist<T, Args...>>
{
    enum { value = 1 };
};


template<typename T, typename typelist> struct append;

template<typename T, typename... Args> 
struct append<T, typelist<Args...>>
{
    using type = typelist<Args..., T>;
};

template<typename typelist> struct len;

template<>
struct len<typelist<>>
{
    enum { value = 0};
};

template<typename T, typename... Args>
struct len<typelist<T, Args...>>
{
    enum { value = 1 + len<typelist<Args...>>::value };
};

template<typename T, typename U> struct concat;

template<typename... Args1, typename... Args2>
struct concat<typelist<Args1...>, typelist<Args2...>>
{
    using type = typelist<Args1..., Args2...>;
};

template<typename T, typename... Args>
struct concat<T, typelist<Args...>>
{
    using type = typelist<T, Args...>;
};

template<typename... Args, typename T>
struct concat<typelist<Args...>, T>
{
    using type = typelist<Args..., T>;
};

template<typename T, typename typelist> struct earse;

template<typename T, typename U, typename... Args> 
struct earse<T, typelist<U, Args...>>
{
    using type = typename concat<U, 
                    typename earse<T, typelist<Args...>>::type
                        >::type;
};

template<typename T, typename... Args>
struct earse<T, typelist<T, Args...>>
{
    using type = typelist<Args...>;
};

template<typename T>
struct earse<T, typelist<>>
{
    using type = typelist<>;
};

template<typename T,  typename typelist> struct earse_all;

template<typename T, typename U, typename... Args>
struct earse_all<T, typelist<U, Args...>>
{
    using type = typename concat<U, 
                    typename earse_all<T, typelist<Args...>>::type
                        >::type;
};

template<typename T, typename... Args>
struct earse_all<T, typelist<T, Args...>>
{
    using type = typename earse_all<T, typelist<Args...>>::type;
};

template<typename T>
struct earse_all<T, typelist<>>
{
    using type = typelist<>;
};


template<typename typelist> struct earse_duplicate;

template<typename T, typename... Args>
struct earse_duplicate<typelist<T, Args...>>
{
    using type = typename concat<T,
                    typename earse_duplicate<
                        typename earse_all<T, 
                            typelist<Args...>>::type>::type
                                >::type;
};

template<>
struct earse_duplicate<typelist<>>
{
    using type = typelist<>;
};

int main()
{
    using integer = typelist<char, char,int ,char,int, char>;
    using new_type = earse_duplicate<integer>::type;
    int l = len<new_type>::value;
    std::cout<<l<<std::endl;
    return 0;
}