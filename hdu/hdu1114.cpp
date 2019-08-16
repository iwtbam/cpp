#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

#define LEN 10001

int dp[LEN];
int val[LEN];
int weight[LEN];
const int INF = 0x3f3f3f3f;

int getK(int V, int C)
{
    int num = V / C;
    return floor(log(num)/ log(2));
}

int main()
{
    int T, E, F, N;

    // freopen("data/hdu1114.txt","r",stdin);

    scanf("%d", &T);
    while(T--&& scanf("%d %d %d", &E, &F, &N)!=-1)
    {
        for(int i = 0; i < N; i++)
            scanf("%d %d", &val[i], &weight[i]);
        
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;

        int V = F - E;

        for(int i = 0; i < N; i++)
        {
            int K = getK(V, weight[i]);
            for(int k = K; k >=  0 ;k--)
            {
                int coe = pow(2, k);
                for(int v = weight[i] * coe ; v <= V; v++)
                {
                    dp[v] = min(dp[v], dp[v - weight[i] * coe] + val[i] * coe);
                }
            }
        }

        if(dp[V] == INF)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[V]);
    }
}