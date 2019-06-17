#include <iostream>
#include <cstring>

#define INF 0x3f3f3f3f
using namespace std;

using ll = long long;

#define maxn 32001

int a[maxn], c[maxn];

int T, n;

inline int lowbit(int x)
{
    return x&(-x);
}

void update(int pos, int x, int n)
{
    while(pos <= n)
    {
        c[pos] += x;
        pos += lowbit(pos);
    }
}

int sum(int x)
{
    int total = 0;
    while(x > 0)
    {
        total += c[x];
        x -= lowbit(x);
    }
    return total;
}


int main()
{
    int n;
    ios::sync_with_stdio(false);
    
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    
    while(cin >> n)
    {
        int x, y;
        int level = n;

        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));

        while(n-- && cin >> x >> y)
        {
            update(x+1, 1, maxn);
            int cur_level = sum(x+1)-1;
            a[cur_level]++;
        }

        for(int i = 0; i < level; i++)
            cout << a[i] << endl;
    }
    return 0;
}