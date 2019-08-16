#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define LEN 10001

int weight[LEN];
float val[LEN];
float dp[LEN];


int main()
{
    int n, m;

    // freopen("data/hdu1203.txt", "r", stdin);

    while(scanf("%d%d", &n, &m)!=-1 && (n || m))
    {
        for(int i = 0; i < m; i++)
            scanf("%d %f", &weight[i] ,&val[i]);

        for(int i = 0; i <= n; i++)
            dp[i] = 1;

        for(int i = 0; i < m ;i++)
        {
            for(int j = n ; j>=weight[i];j--)
                dp[j] = min(dp[j], dp[j - weight[i]] * (1- val[i]));
        }
    
        printf("%.1f%%\n", (1- dp[n])*100); 
    }
}