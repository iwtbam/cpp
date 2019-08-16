#include <cstdio>
#include <cstring>

using namespace std;

#define N 1000001

long long INF = __INT_LEAST64_MAX__;

short num[N];
long long dp[N];
long long pre[N];

inline long long max(long long x, long long y)
{
    return x > y ? x : y;
}

int main()
{
    int m, n;
    
    freopen("data/hdu1024.txt", "r", stdin);

    while(scanf("%d%d", &m, &n)!=EOF)
    {
        for(int i = 1; i <= n ; i++)
            scanf("%hd", &num[i]);
        
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));

        long long temp;

        for(int i = 1; i <= m;i++)
        {
            temp = -INF;

            for(int j = i; j <= n; j++)
            {
                dp[j] = max(dp[j-1], pre[j-1]) + num[j];
                pre[j-1] = temp;
                temp = max(temp, dp[j]);
            }
        }

        printf("%lld\n",temp);
    }

    return 0;
}


//  dp[i][j] = max(dp[i][j-1], max(dp[i-1][k])) + num[j] ( i-1 <= k <= j-1)
//  dp[i][j] 前j个数字分成i个子序列的最大和

//  空间优化
//  dp[j] = max(dp[j],  pre[j-1]) + num[j] 
//  pre[k] = max(dp[i][k]) (i - 1 <= k <= j - 1) 