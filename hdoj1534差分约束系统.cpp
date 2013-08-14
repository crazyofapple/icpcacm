#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <cmath>
#define inf 0x3f3f3f3f
#define maxn 1006
using namespace std;

struct Edge
{
    int next;
    int v;
    int w;
}e[maxn*maxn];

int adj[maxn], cnt, n;
int dis[maxn],p[maxn],a[maxn];
bool vis[maxn];
void addedge(int u, int v, int w)
{
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=adj[u];
    adj[u]=cnt++;
}

bool spfa()
{
    memset(vis,false,sizeof(vis));
    for (int i = 1; i <= n; i++) dis[i] = -inf;
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int t = q.front();q.pop();
        vis[t] = false;
        for (int i = adj[t]; i != -1; i=e[i].next)
        {
            int v=e[i].v;
            int w=e[i].w;
            if(dis[v]<dis[t]+w)
            {
                dis[v] = dis[t]+w;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                    if((++p[v])>n) return false;
                }

            }
        }
    }
    return true;
}
int main()
{
    int cas = 0;
    int x, y;
    string str;
    while(~scanf("%d",&n))
    {
        if(!n)break;
        cnt=0;
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        memset(adj,-1,sizeof(adj));
        for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
        while(1)
        {
            cin >> str;
            if(str[0] == '#')break;
            scanf("%d%d",&x,&y);
            if(str == "SAS")
            {
                addedge(y, x, 0);
            }
            else if(str == "SAF")
            {
                addedge(y, x, a[y]);
            }
            else if(str == "FAS")
            {
                addedge(y, x, -a[x]);
            }
            else if(str == "FAF")
            {
                addedge(y, x, a[y]-a[x]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            addedge(0, i, 0);
        }
        printf("Case %d:\n",++cas);
        if(spfa())
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d %d\n", i, dis[i]);
            }
        }
        else
        {
            printf("impossible\n");
        }
        cout << endl;
    }
    return 0;
}
