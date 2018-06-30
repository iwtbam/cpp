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
    for(int i = 0;i<elems.size()-1 ;i++)
    {
        for(int j = 0;j<elems.size()-1-i;j++)
        {
            if(compare(elems.at(j),elems.at(j+1)))
            {
                Swap(elems.at(j),elems.at(j+1));
            }
        }
    }
}

bool greater(int left, int right)
{
    return left > right;
}


int main()
{
    std::vector<int> elems = {1,3,5,32,0,535,-19,4543,0,-7};
    BubbleSort<int>(elems,greater);
    for(int i = 0;i<elems.size();i++)
    {
        std::cout<<elems.at(i)<<std::endl;
    }
    std::cout<<std::endl;
    return 0;
}