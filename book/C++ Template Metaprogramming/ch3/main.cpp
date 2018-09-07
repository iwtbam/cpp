#include <functional>
#include <iostream>

using namespace std;

int test(int a, int b)
{
    std::cout<<"a:"<<a<<std::endl;
    std::cout<<"b:"<<b<<std::endl;
    return 0;
}

int main()
{
    auto f = bind(test, std::placeholders::_2, std::placeholders::_1);
    f(5,6);
    return 0;
}