#include <cstdio>
#include <cmath>
#include <algorithm>


#define LEN 501

using namespace std;

long long sum[LEN * LEN];


int A[LEN], B[LEN], C[LEN];

bool binary_search(int target, int len)
{
    int low = 0, high = len-1;
    while(low <= high)
    {
        int middle = (low+high) >> 1;
        if(sum[middle]==target)
            return true;
        else if(sum[middle] > target)
            high = middle - 1;
        else
            low = middle + 1;
    }
    return false;
}


int main()
{
    // freopen("data/hdu2141.txt", "r",stdin);

    int l, n, m;
    int c(1);
    while(scanf("%d %d %d", &l, &n, &m)!=EOF)
    {
        for(int i = 0; i < l ; i++)
            scanf("%d", A+i);
        for(int i = 0; i < m ; i++)
            scanf("%d", B+i);
        for(int i = 0; i < n ; i++)
            scanf("%d", C+i);
        
        int len = l * m;

        for(int i = 0; i < l; i++)
            for(int j = 0; j < m; j++)
                sum[i*m+j] = A[i] + B[j];
        
        sort(sum, sum + len);

        printf("Case %d:\n",c++);
        int s, r;
        scanf("%d", &s);
        while(s--&&scanf("%d",&r)!=EOF)
        {
            bool isFind = false;
            for(int i = 0; i < n ;i++)
            {
                int target = r - C[i];
                isFind = binary_search(target, len);
                if(isFind)
                    break;
            }

            if(isFind)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;

}


