#include <iostream>
#include <string>

 

// 如果一个字符串可以由某个长度为k的字符串重复多次得到,我们说该串以
// k为周期。例如abcabcabcabc以3为周期（6和 12)也是周期。输入一个
// 长度不超过80的串，输出它的最小周期。


int solution1(const std::string& s)
{
    int k = 1;
    bool isK = false;
    for(;(!isK) && k <= s.size(); k++)
    {
        if(s.size() % k)
            continue;
     
        isK = true;

        for(int i = 0;  isK && i < k ;i++)
        {
            for(int j = i+k;j < s.size(); j+=k)
            {
                if(s.at(j) != s.at(i))
                {
                    isK = false;
                    // std::cout<<k<<'\t'<<s.at(i)<<'\t'<<s.at(j)<<'\t'<<std::boolalpha<<isK<<std::endl;
                    break;
                }
                // std::cout<<k<<'\t'<<s.at(i)<<'\t'<<s.at(j)<<'\t'<<std::boolalpha<<isK<<std::endl;
            } 
        }
    }

    return (k-1);
}

int solution2(const std::string& s)
{
    for(int i = 1;i<s.size();i++)
    {
        if(s.size()%i)
            continue;
        
        for(int k = i;k<s.size();k++)
        {
            bool isK = true;
            if(s.at(k)!=s.at(k%i))
            {
                isK = false;
                break;
            }
            if(isK)
                return k;
        }
    }
    return s.size();
}


int main()
{
    std::string s = {"abcdabcdabcde"};
    std::cout<<solution1(s)<<std::endl;
    return 0;
}