#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <cstring>

#define LEN 20

using namespace std;

bool isPrime(int n)
{
    if(n==1)
        return false;
    else
    {
        int i = 2;
        for(; i<=sqrt(n);i++)
            if(n%i==0)
                return false;
        return true;
    }
    return false;
}

int ring[LEN];
int visited[LEN];
int n;
int solved = false;
int num = 0;

void dfs(int pos)
{

    if(pos>n-1)
    {
        return;
    }

    for(int j = 2;j<=n;j++)
    {
        if(visited[j])
            continue;
        
        ring[pos] = j;

        if(isPrime(j+ring[pos-1]))
        {
            visited[j] = 1;

            if(pos==n-1)
            {
                if(isPrime(ring[pos]+1))
                {
                    for(int i = 0;i<n-1;i++)
                        printf("%d ",ring[i]);
                    printf("%d\n",ring[n-1]);   
                }
            }
            dfs(pos+1);
            visited[j] = 0;
        }

    }
}


int main()
{
    // freopen("data/hdu1016.txt","r",stdin);
    // freopen("data/hdu1016c.txt","w",stdout);
    while(scanf("%d",&n)!=EOF&&n>0&&n<20)
    {
        num++;        
        memset(visited,0,sizeof(visited));

        printf("Case %d:\n",num);
        if(n%2==0)
        {
            ring[0] = 1;
            visited[1] = 1;
            dfs(1);
        }
        printf("\n");
       
    }
}

// 对于dfs+回溯感觉练习还是太少了
//此题输出格式真坑 很容易 PE