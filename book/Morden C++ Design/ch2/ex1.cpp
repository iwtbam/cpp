#include <iostream>
#include <cassert>

using namespace std;

template<typename To, typename From>
To safe_cast(From from)
{
    assert(sizeof(From)<sizeof(To));
    //编译期阶段无法判断结果
    return (To)(from);
};


//表达式的值会在编译期阶段被计算

template<bool>
struct ComplieTimeError{};
template<>
struct ComplieTimeError<true>{};

//以下均失败
#define static_check_0(epr) {char a[(epr)?1:0];}
#define static_check_1(epr) (ComplieTimeError<(epr)!=0>())


template<typename To, typename From>
To safe_cast_1(From from)
{
    static_check_0(sizeof(From)<=sizeof(To));
    return (To)(from);
}

template<typename To, typename From>
To safe_cast_2(From from)
{
    static_check_1(sizeof(From)<=sizeof(To));
    return (To)(from);
}

//static_check_2 可以实现 匿名使用模板达不到效果
template<bool>
struct ComplieTimeChecker
{
    ComplieTimeChecker(...);
};

template<>
struct ComplieTimeChecker<false>{};

#define static_check_2(expr,msg)                                      \
{                                                                     \
    class Error_##msg {};                                             \
    auto error = ComplieTimeChecker<(expr)>(Error_##msg());           \
}


template<bool>
struct test
{
    static int value;
    test();
};

template<bool v> int test<v>::value;

template<bool v> test<v>::test()
{
    value = 1;
}

int main()
{

//   test<true>();
//   std::cout<<test<true>::value<<std::endl;
//   std::cout<<test<false>::value<<std::endl;
  

  return 0;
}
