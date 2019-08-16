#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

//没有A 但我感觉没问题
using namespace std;

#define N 50001

int c[N];

inline int lowbit(int x)
{
    return x & (-x);
}

int update(int pos, int x, int n)
{
    while(pos <=n)
    {
        c[pos] += x;
        pos += lowbit(pos);
    }
    return c[pos];
}

int sum(int pos)
{
    int res = 0;
    while(pos > 0)
    {
        res += c[pos];
        pos -= lowbit(pos);
    }
    return res;
}

int range_sum(int st, int ed)
{
    return sum(ed) - sum(st-1);
}

int main()
{

    ios::sync_with_stdio(false);

    int T, n;
    cin >> T;
    int case_id = 1;
    while(T-- && cin >>n)
    {
        memset(c, 0, sizeof(int)*(n+1));
        for(int i = 1; i <=n;i++)
        {
            int data;
            cin >> data;
            update(i, data, n);
        }

        cout << "Case:" << case_id << endl;
        case_id++;

        string token;
        int v1, v2;
        
        while(cin >> token)
        {

            if(token != "End")
            {
                cin >> v1 >> v2;
                if(token == "Query")
                {
                    cout << range_sum(v1, v2) << endl;
                }
                else if(token == "Add")
                {
                    update(v1, v2, n);
                }
                else if(token == "Sub")
                {
                    update(v1, -v2, n);
                }
            }
            else
            {
                break;
            }            
        }
    }
}
