#include <iostream>

template<int N, int M>
struct gcd:
	gcd<M, N%M>
{};

template<int N>
struct gcd<N, 0>
{
	static const int value = N;
};

int main(int argc, char** argv)
{
	int value1 = gcd<80,15>::value;
	std::cout<<value1<<std::endl;
	int value2 = gcd<6,9>::value;
	std::cout<<value2<<std::endl;
	int value3 = gcd<34,2>::value;
	std::cout<<value3<<std::endl;
	return 0;
}