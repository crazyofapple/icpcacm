#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#define maxn 206
using namespace std;

struct Edge
{
    int v;
    int next;
}e[maxn*maxn];
int cnt,adj[maxn];

void addedge(int u, int v)
{
    e[cnt].v=v;
    e[cnt].next=adj[u];
    adj[u]=cnt++;
}
bool vis[maxn];
int n, m;
int mark[maxn];

int dfs(int u)
{
    for (int t = adj[u]; t != -1; t=e[t].next)
    {
        int v=e[t].v;
        if(!vis[v])
        {
            vis[v]=true;
            if(mark[v]==-1 || dfs(mark[v]))
            {
                mark[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hug()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(vis,false,sizeof(vis));
        if(dfs(i)) ans++;
    }
    return ans;
}
int main()
{
    int t, j;
    while(~scanf("%d%d",&n,&m))
    {
        memset(mark,-1,sizeof(mark));
        memset(adj,-1,sizeof(adj));
        cnt=0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d",&t);
            while(t--)
            {
                scanf("%d",&j);
                addedge(i,j);
            }
        }
        cout << hug() << endl;
    }
}
