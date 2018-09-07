#include <iostream>
#include "type_traits.hpp"
#include <type_traits>
#include <vector>

// using namespace iwtbam;

class A {};
class B:public A{};

int main()
{
    // std::cout<< conversion<int,double>::exists << std::endl;

    // bool v1 = SUPERSUBCLASS(A, B);
    // bool v2 = SUPERSUBCLASS(B, A);

    // // std::cout << v1 << "\t" << v2 <<std::endl;
    // bool v3 = pointer_traits<std::vector<int>::iterator>::value;
    // bool v4 = pointer_traits<int*>::value;
    // std::cout<<"iterator is pointer:"<<std::boolalpha<<v3<<std::endl;
    // std::cout<<"int* is pointer:"<<std::boolalpha<<v4<<std::endl;

    // std::is_member_function_pointer
    // std::is_member_object_pointer
    return 0;
}