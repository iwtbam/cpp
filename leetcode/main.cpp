#include <string>
#include <iostream>
#include <sstream>

using namespace std;


template<typename T>
string toString(T val)
{
    stringstream ss;
    ss << val;
    return ss.str();
} 

template<typename T>
T toVal(string s)
{
    T val;
    stringstream ss;
    ss << s;
    ss >> val;
    return val;
}

int main()
{
    // string s = toString(555);
    // cout << toVal<int>(s) << endl;
   
    char* p = "hello world!";

    string s(p);

    cout << s << endl;
    
    return 0;
}