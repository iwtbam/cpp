// 树状数组求逆序数

#include <iostream>
#include <cstring>

using namespace std;
#define N 1010
int c[N];

inline int lowbit(int x)
{
    return x & (-x);
}


int update(int pos, int val, int n)
{
    while(pos <= n)
    {
        c[pos] += val;
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

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    while(cin >> n)
    {
        int ans = 0;
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            update(a, 1, n);
            ans += i - sum(a);   
        }
        cout << ans << endl;
    }
    return 0;
}
