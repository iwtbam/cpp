#include <cstdio>
#include <cstring>

#define LEN 200000
int dp[LEN];
int num[7];


int main()
{
    int k = {1};
    // freopen("data/hdu1059.txt", "r", stdin);
    // while(scanf("%d%d%d%d%d%d", &num[1], &num[2], &num[3], &num[4], &num[5], &num[6])!=EOF)
    while(1)
    {
        int sum = 0;
        for(int i = 1; i <= 6;i++)
        {
            scanf("%d", &num[i]);
            sum += i * num[i];
        }

        if(!sum)
            break;

        memset(dp, -1, sizeof(dp));
        dp[0] = 0;

        printf("Collection #%d:\n", k++);

        if(sum % 2)
        {
            printf("Can't be divided.\n\n");
            continue;
        }
     
        int V = sum / 2;
        for(int i = 1;i <= 6; i++)
        {
            for(int j = 0; j <= V; j++)
            {
                if(dp[j]>=0)
                    dp[j] = num[i];
                else if(j<i || dp[j-i]<=0)
                    dp[j] = -1;
                else
                    dp[j] = dp[j-i] - 1;
            }
        }

        if(dp[V] >= 0)
            printf("Can be divided.\n");
        else
            printf("Can't be divided.\n");   
        printf("\n");
        
    }
    return 0;
}
// TLE 

// #define LEN 7
// #define VAL 6001
// #define max(a, b) ((a)>(b)?(a):(b))

// int num[LEN];
// int dp[LEN][VAL];

// int main()
// {

//     freopen("data/hdu1059.txt","r", stdin);
//     int k = 1;
//     while(1)
//     {
//         int sum = {0};
//         for(int i = 1; i<= 6; i++)
//         {
//             scanf("%d", &num[i]);
//             sum += num[i] * i;
//         }

//         if(sum == 0)
//             break;


//         printf("Collection #%d:\n", k++);

//         if(sum %2)
//         {
//             printf("Can't be divided.\n");
//             printf("\n");
//             continue;
//         }

//         int V = sum / 2;

//         memset(dp[0], -1, sizeof(dp[0]));
//         dp[0][0] = 0;

//         for(int i = 1; i <= LEN ;i++)
//         {
//             for(int j = 0; j <= V; j++)
//             {
//                 if(dp[i-1][j] >= 0)
//                     dp[i][j] = num[i];
//                 else
//                     dp[i][j] = -1;
//             }

//             if(!num[i])
//                 continue;
            
//             for(int j = 0; j <= V - i; j++)
//             {
//                 if(dp[i][j] > 0)
//                     dp[i][j+i] = max(dp[i][j+i], dp[i][j]-1); 
//             }
//         }

//         if(dp[6][V]!=-1)
//             printf("Can be divided.\n");
//         else
//             printf("Can't be divided.\n");
        
//         printf("\n");
        
//     }

//     return 0;
// }


