///最大团等于G的补图的最大独立集而补图的最大独立集等于 == 其顶点数-最大匹配数
#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 206
using namespace std;

int map[maxn][maxn];
bool vis[maxn];
int mark[maxn];
int g,b,m;

bool dfs(int u)
{
    for(int i = 1; i <= b; i++)
    {
        if(!vis[i] && map[u][i])
        {
            vis[i]=true;
            if(mark[i] == -1 || dfs(mark[i]))
            {
                mark[i]=u;
                return true;
            }
        }
    }
    return false;
}
int hug()
{
    int ans = 0;
    for (int i = 1; i <= g; i++)
    {
        memset(vis,false,sizeof(vis));
        if(dfs(i))ans++;
    }
    return ans;
}
int main()
{
    int cas=0,x,y,ans;
    while(cin >> g >> b >> m)
    {
        if(!g&&!b&&!m)break;
        ans = 0;
        memset(mark,-1,sizeof(mark));
        for (int i = 1; i <= g; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                map[i][j] = 1;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            map[x][y]=0;
        }
        ans = g+b-hug();
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
