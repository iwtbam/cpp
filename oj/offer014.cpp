// 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
// 打印能拼接出的所有数字中最小的一个。
// 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
       
       vector<string> str_numbers;
       stringstream ss;

       for(auto number :numbers)
       {
           string str_number;
           ss << number;
           str_number = ss.str();
           ss.clear();
           ss.str("");
           str_numbers.push_back(str_number);
       }

       sort(str_numbers.begin(), str_numbers.end(), [](string s1, string s2)->bool{
           string s12 = s1 + s2;
           string s21 = s2 + s1;
           return s12 < s21;
       });
       string sum = accumulate(str_numbers.begin(), str_numbers.end(), string(""));
       return sum;
    }
};