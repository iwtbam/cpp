//实现一个简单的tuple

#include <iostream>

template<typename... Args> struct tuple;

template<>
struct tuple<>{};

template<typename T, typename... Args>
struct tuple<T, Args...>:
    tuple<Args...>
{
    tuple() = default;
    tuple(T v, Args... args):value(v), tuple<Args...>(args...){};
    T value;
};

template<int v> struct Int2Type { enum {value = v};};

template<int i, typename tuple> struct at;

template<int i, typename T, typename... Args>
struct at<i, tuple<T, Args...>>:
    at<i-1,tuple<Args...>>
    {};

template<typename T, typename... Args>
struct at<0, tuple<T, Args...>>
{
    using type = T;
};

template<int i, typename T, typename... Args>
typename at<i, tuple<T, Args...>>::type&
    get_helper(tuple<T, Args...>& t, Int2Type<i>)
{
    auto& base = static_cast<tuple<Args...>&>(t); 
    return get_helper(base, Int2Type<i-1>());
}

template<typename T, typename...Args>
T& get_helper(tuple<T,Args...>& t, Int2Type<0>)
{
    return t.value;
}

template<int i, typename... Args>
typename at<i, tuple<Args...>>::type&
    get(tuple<Args...>& t)
{
    return get_helper(t, Int2Type<i>());
}

using Point3d = tuple<int, int, int>;

int main()
{
    tuple<int, int, std::string> p = {0,1,"hello world"};

    return 0;
}