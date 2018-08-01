#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;


//没A 想不通 样例没过 
//枚举不行，时间是连续

int main()
{
    int D;
    int total = 12 * 64800;
    // auto t = clock();
    // freopen("data/hdu1006.txt","r",stdin);
    while(scanf("%d",&D)!=EOF&&D!=-1)
    {
        float happy = 0;
        float sangle, mangle, hangle;
        for(int i = 0;i<12;i++)
        {
            for(int j = 0;j<60;j++)
            {
                for(int k= 0;k<1080;k++)
                {
                    sangle = k * 0.33333;
                    mangle = j * 6 + sangle / 60.0;
                    hangle = i * 30 + mangle / 12.0;

                    float d1 = fabs(sangle-mangle);
                    d1 = d1 >= 180 ? 360 - d1 : d1;
                    float d2 = fabs(mangle - hangle);
                    d2 = d2 >= 180 ? 360 - d2 : d2;
                    float d3 = fabs(hangle - sangle);
                    d3 = d3 >= 180 ? 360 - d3 : d3;

                    if(d1>=D&&d2>=D&&d3>=D)
                    {
                        happy++;
                    }
                }
            }
        }

        float per = happy * 100 / total;
        printf("%0.3f\n",per);
    }
    // auto t2 = clock();
    // printf("%ld\n",t2-t);
}