#include <cstdio>
using namespace std;

#define LEN 1000
int f[LEN];

int  main()
{
    int A, B, n;
    f[0] = 1,f[1] = 1;

    while(scanf("%d%d%d",&A,&B,&n)!=EOF && (A||B||n))
    {
        int z = 2;

        for(int i = 2;i<n && i<LEN;i++)
        {
            f[i] = (A*f[i-1] + B*f[i-2])%7;
            if(f[i]!=f[i%z])
                z++;
        }


        if(n>LEN)
            printf("%d\n",f[(n-1)%z]);
        else
            printf("%d\n",f[n-1]);

        // printf("%d\n",z);
       
    }
    return 0;
}


//理论不明 