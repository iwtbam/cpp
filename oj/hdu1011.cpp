#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>






//心态炸了， 思路完全错了

// #define LEN 101

// int price[LEN];
// int val[LEN];
// int dp[LEN];
// int pre[LEN];
// int vis[LEN];
// int map[LEN][LEN];

// using namespace std;

// vector<int> path;

// int n, m;
// int max_prob;

// inline int max(int x, int y)
// {
//     return x>y?x:y;
// }

// void dfs(int root)
// {
//     path.push_back(root);
//     vis[root] = 1;

//     for(int V = m; V>=price[root];V--)
//     {
//         pre[V] = dp[V];
//         dp[V] = max(dp[V], dp[V-price[root]]+val[root]);
//     }

//     bool isLeaf = true;

//     for(int i = 1; i<=n;i++)
//     {
//         if(!vis[i] && map[root][i])
//         {
//             dfs(i);
//             isLeaf = false;
//         }
//     }

//     if(isLeaf)
//         max_prob = max(max_prob, dp[m]);

//     for(int V=m; V>=price[root];V--)
//         dp[V] = pre[V];

//     vis[root] = 0;
//     path.pop_back();
// }


// int main()
// {
//     // freopen("data/hdu1011.txt", "r", stdin);

//     while(scanf("%d%d", &n, &m)!=EOF && (n != -1 || m != -1))
//     {
//         for(int i = 1; i <= n ; i++)
//         {
//             scanf("%d%d", &price[i], &val[i]);
//             price[i] = ceil(price[i]/20.0);
//             if(price[i]==0)
//                 price[i] = 1;
//         }

//         max_prob = -__INT_MAX__;

//         memset(map, 0, sizeof(map));
//         memset(dp, 0, sizeof(dp));
//         memset(pre, 0, sizeof(pre));
//         memset(vis, 0, sizeof(vis));

//         int t1, t2; 

//         for(int i = 1; i <= n-1; i++)
//         {
//             scanf("%d%d", &t1, &t2);
//             map[t1][t2] = 1;    
//         }

//         dfs(1);

//         printf("%d\n", max_prob);
//     }
//     return 0;
// }