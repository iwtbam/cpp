#include <cstdio>
#include <cstring>
#include <cmath>

#define max(a, b) ((a) > (b)?(a):(b))
#define LEN 101

int dp[LEN];
int price[LEN];
int weight[LEN];
int num[LEN];


int main()
{
    int T, n, m;
    // freopen("data/hdu2191.txt","r",stdin);
    scanf("%d", &T);

    while(T-- && scanf("%d %d", &n, &m)!=-1)
    {
        for(int i = 0; i<m ;i++)
            scanf("%d %d %d", &price[i], &weight[i], &num[i]);
        
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i<m;i++)
        {
            for(int k = 1;k <= num[i] ;k++)
            {
                for(int v = n; v >= price[i]; v--)
                    dp[v] = max(dp[v], dp[v - price[i]] + weight[i]);
            }
        }

        printf("%d\n", dp[n]);
    }
}
