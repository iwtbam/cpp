#include <cstdio>
#include <cmath>
#include <functional>

using namespace std;

inline double f(double x, double y)
{
    return 8*pow(x, 4)+7*pow(x,  3)+2*pow(x, 2)+3*x+6-y;
}

int main()
{
    int t;
    double y;

    // freopen("data/hdu2199.txt","r", stdin);
    while(scanf("%d", &t)!=EOF)
    {
        while(t--&&scanf("%lf", &y)!=EOF)
        {
            auto tempF = bind(f, placeholders::_1, y);
            double l = 0.0;
            double h = 100.0;
            double lvalue = tempF(l);
            double rvalue = tempF(h);
            if(lvalue*rvalue>0)
            {
                printf("No solution!\n");
                continue;
            }

            double mid = (l + h)/2;
            double pmid = l;
            while(fabs(mid-pmid)>1e-5 || fabs(tempF(mid))>1e-5)
            {
                pmid = mid;
                if(tempF(l)*tempF(mid)<0.0)
                {  
                     h = mid;
                     mid = (l + mid)/2.0;
                }
                else
                {
                    l = mid;
                    mid = (mid + h)/2.0;
                }
            }

            printf("%0.4lf\n",mid);
            // printf("%lf\n",tempF(mid));

        }
    }

    // printf("%lf\n",f(1.8271,150));
    // printf("%lf\n",f(1.5054,80));
}

//精度问题