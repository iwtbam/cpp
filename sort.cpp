#include <iostream>
#include <vector>
#include <functional>


template<typename _ElemType>
void Swap(_ElemType& elem1, _ElemType& elem2)
{
    elem2 =  elem1 + elem2;
    elem1 =  elem2 - elem1;
    elem2 =  elem2 - elem1;
}

template<typename ElemType>
void BubbleSort(std::vector<ElemType>& elems, std::function<bool(ElemType, ElemType)> compare)
{

}

bool greater(int left, int right)
{
    return true;
}


int main()
{
    int a = 10, b = 20;
    Swap(a, b);
    std::cout<<"a:"<<a<<std::endl;
    std::cout<<"b:"<<b<<std::endl;
    return 0;
}