#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        
        int* record = new int[length];        
        for(int i = 0; i< length; i++)
            record[numbers[i]]++;
        
        for(int i = 0; i< length;i++)
        {
            if(record[i] == 2)
            {
                *duplication = i;
                return true;
            }
        }
        
        delete[] record;
        return false;
    }
};

int main()
{
    int numbers[] = {2,4,3,1,4};
    int l = 5;
    Solution s;
    int name;
    s.duplicate(numbers, 4, &name);
    cout << name <<endl;
}