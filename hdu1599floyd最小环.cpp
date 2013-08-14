#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define inf 999999
#define maxn 106
using namespace std;

int n, m, min1;
int dis[maxn][maxn];
int map[maxn][maxn];

void floyd()
{
    min1=inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = map[i][j];
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
        {
            for (int j = 1; j < i; j++)
            {
                min1 = min(min1, dis[i][j] + map[j][k] + map[k][i]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
}
int main()
{
    int x, y, z;
    while (~scanf("%d%d",&n,&m))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                map[i][j] = inf;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &x,&y,&z);
            if(map[x][y] > z)
            {
                map[x][y] = map[y][x] = z;
            }
        }
        floyd();
        if(min1 == inf)
        {
            printf("It's impossible.\n");
        }
        else
        {
            printf("%d\n",min1);
        }
    }
    return 0;
}


