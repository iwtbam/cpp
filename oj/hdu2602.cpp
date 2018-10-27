#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define LEN 1001

int dp[LEN];
int val[LEN];
int weight[LEN];

int main()
{
    // freopen("data/hdu2602.txt","r", stdin);
    int num, N, V;
    scanf("%d", &num);
    while(num-- && scanf("%d %d", &N, &V)!=-1)
    {
        for(int i = 0; i < N; i++)
            scanf("%d", &val[i]);
        
        for(int i = 0; i< N; i++)
            scanf("%d", &weight[i]);

        memset(dp, 0, sizeof(dp));

        for(int i =0 ; i < N; i++)
        {
            for(int v = V; v >= weight[i]; --v)
                dp[v] = max(dp[v], dp[v - weight[i]] + val[i]);

        }

        printf("%d\n", dp[V]);
    }  
}