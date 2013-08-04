#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#define inf 0x3f3f3f3f
#define maxn 1006
using namespace std;

struct Edge
{
    int v;
    double w;
    int next;
}e[maxn*maxn];
int adj[maxn], cnt;
int p[maxn];
double dis[maxn];
bool vis[maxn];
int n, m;

void addedge(int u, int v, double w)
{
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=adj[u];
    adj[u]=cnt++;
}

bool spfa()
{
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= (n + m); i++) dis[i] = inf;
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    p[1]++;
    while(!q.empty())
    {
        int t = q.front(); q.pop();
        vis[t] = false;
        for (int i = adj[t]; i != -1; i = e[i].next)
        {
            int v=e[i].v;
            double w=e[i].w;
            if(dis[v] > dis[t] + w)
            {
                dis[v]=dis[t]+w;
                if(!vis[v])
                {
                    vis[v]= true;
                    q.push(v);
                    if((++p[v])>(int)sqrt(1.0*(n+m)))
                    return false;
                }

            }
        }
    }
    return true;
}
int main()
{
    double l,u,c;
    while(~scanf("%d%d%lf%lf", &n, &m, &l, &u))
    {
        memset(adj,-1,sizeof(adj));
        memset(p,0,sizeof(p));
        cnt=0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%lf",&c);
                addedge(i, j+n, -log(1.0*l/c));
                addedge(j+n, i, log(1.0*u/c));
            }
        }
        if(spfa())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
