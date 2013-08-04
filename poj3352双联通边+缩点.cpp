///low值相同的在一个边连通分量

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define maxn 1006
using namespace std;

struct Edge
{
    int v;
    int next;
}e[maxn];
int low[maxn], vis[maxn], deg[maxn];
int adj[maxn], index, cnt;
int n, m,ans;

void addedge(int u, int v)
{
    e[cnt].v=v;
    e[cnt].next=adj[u];
    adj[u]=cnt++;
}
void dfs(int u, int v)
{
    low[u]=++index;
    vis[u]=true;
    for (int t=adj[u]; t!=-1; t=e[t].next)
    {
        int tv=e[t].v;
        if(tv==v)continue;
        if(!vis[tv])dfs(tv,u);
        low[u]=min(low[u],low[tv]);
    }
}
int main()
{
    int x, y;
    cin >> n >> m;
    memset(adj,-1,sizeof(adj));
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        addedge(x, y);
        addedge(y, x);
    }
    dfs(1, 1);
    for (int i = 1;i <= n; i++)
    {
        for (int t=adj[i];t!=-1;t=e[t].next)
        {
            int v=e[t].v;
            if(low[v] != low[i])
            {
                deg[ low[i] ]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if(deg[i] == 1)
        {
            ans++;
        }
    }
    cout << (ans+1)/2 << endl;
    return 0;
}
