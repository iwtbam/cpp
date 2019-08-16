#include <cstdio>
#include <algorithm>

using namespace std;

#define  LEN 10005

typedef struct FoodsAcount
{
    int F;
    int J;
}FA;

FA FJ[LEN];

bool comp(const FA& f1, const FA& f2)
{
    float rate1 = 100.0;
    float rate2 = 100.0;

    if(f1.F)
        rate1 = f1.J * 1.0 / f1.F;

    if(f2.F)
        rate2 = f2.J * 1.0 / f2.F;


    return rate1 < rate2;
}

int main()
{
    // freopen("data/hdu1009.txt","r", stdin);
    int M, N;
    while(scanf("%d%d",&M,&N))
    {
        if(M==-1&&N==-1)
            break;

        double total = {0};
        double res = M;

        for(int i = 0;i<N;i++)
            scanf("%d%d",&FJ[i].F, &FJ[i].J);


        if(M==0||N==0)
        {
            printf("%0.3f\n",total);
            continue;
        }
        
        sort(FJ,FJ+N,comp);

        
        for(int i=0; i<N;i++)
        {
            if(res>=FJ[i].J)
            {
                res -= FJ[i].J;
                total += FJ[i].F;
            }
            else
            {
                total += FJ[i].F * res / FJ[i].J;
                res = 0;
                break;
            }
        }

        
        printf("%0.3lf\n",total);

    }
}


//除法 除0判断