/*
4
0 0 0
0 1 1
1 1 2
1 0 3
0

有带权图G, 对于图中每条边e[i], 都有benifit[i](收入)和cost[i](花费),
我们要求的是一棵生成树T, 它使得 ∑(benifit[i]) / ∑(cost[i]), i∈T 最大(或最小).
设x[i]等于1或0, 表示边e[i]是否属于生成树.
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#define maxn 1006
#define inf 0x3f3f3f3f
#define eps 1e-5
using namespace std;

double x[maxn],y[maxn],z[maxn];
double map[maxn][maxn], dis[maxn][maxn];
double dis2[maxn],cost[maxn][maxn];
bool vis[maxn];
int p[maxn] ,n;
int min1, t;

double prim(double rat)
{
    memset(map,0,sizeof(map));
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            map[i][j] = map[j][i] = cost[i][j] - rat * dis[i][j];
        }
    }
    //建图
    memset(vis,false,sizeof(vis));
    fill(p,p+maxn,1);
    for (int i = 1; i <= n; i++)
    {
        dis2[i] = map[1][i];
    }
    vis[1] = true;
    for (int i = 2; i <= n; i++) //n-1条边
    {
        min1 = inf;t=0;
        for (int j = 2; j <= n; j++)
        {
            if(!vis[j] && min1 > dis2[j])
            {
                min1 = dis2[j];t=j;
            }
        }
        vis[t]=true;
        for (int j = 2; j <= n; j++)
        {
            if(!vis[j] && dis2[j] > map[t][j])
            {
                dis2[j]=map[t][j];p[j]=t;
            }
        }
    }
    double sumd=0,sumc=0;
    for (int i = 2; i <= n; i++)
    {
        sumd+=dis[i][p[i]];
        sumc+=cost[i][p[i]];
    }
    return sumc/sumd;
}
int main()
{
    while(~scanf("%d",&n))
    {
        if(n==0)break;
        memset(dis,0,sizeof(dis));
        memset(cost,0,sizeof(cost));
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i] >> z[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i+1; j <= n; j++)
            {
                dis[i][j] = dis[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j])
                                           + (y[i]- y[j]) * (y[i]- y[j]));
                cost[i][j]=cost[j][i] = abs(z[i]-z[j]);
            }
        }
        double r2=0,r1=0;
        while(1)
        {
            r2=prim(r1);
            if(abs(r1-r2)<eps)
            {
                break;
            }
            r1=r2;
        }
        printf("%.3lf\n",r1);
    }
    return 0;
}
