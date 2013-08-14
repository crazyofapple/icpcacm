#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 0x3f3f3f3f
#define maxn 5
#define maxn1 100006
using namespace std;

int n;
struct Point
{
    double x[6];
} p[maxn1];
double ma[1<<5], mi[1<<5];
int main()
{
    while(~scanf("%d",&n))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                cin >> p[i].x[j];
            }
        }
        for (int i = 0; i < (1<<5); i++)
        {
            ma[i]=-inf;
            mi[i]=inf;
        }
        int t=0;
        double sum=0;
        for (int j = 0; j < (1<<5); j++)
        {

           for (int i = 1; i <= n; i++)
           {
               t = j;sum = 0;
               for (int k = 1; k <= 5; k++)
               {
                   if(t&(1))
                   {
                       sum+=p[i].x[k];
                   }
                   else
                   {
                       sum-=p[i].x[k];
                   }
                   t >>= 1;
               }
               ma[j] = max(sum, ma[j]);
               mi[j] = min(sum, mi[j]);
           }

        }
        double ans = -1;
        for (int i = 0; i < (1<<5); i++)
        {
            ans = max(ans, ma[i] - mi[i]);
        }
        printf("%.2lf\n",ans);

    }
    return 0;
}
