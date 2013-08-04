///题意：有n个区间，要求每个区间有Ci个数,若使这n个区间都符合要求
///问至少需要多少个数。（1<n<50000）
/*
5
3 7 3
8 10 3
6 8 1
1 3 1
10 11 1
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define maxn 50006
#define inf 0x3f3f3f3f
using namespace std;

int dis[maxn*3],cnt,n,max1,min1;
bool vis[maxn*3];

struct Edge
{
    int v;
    int w;
    Edge *next;
}*adj[maxn*3],e[maxn*3];

void addedge(int u, int v, int w)
{
    Edge *p = &e[cnt++];
    p->v = v; p->w = w; p->next=adj[u];adj[u]=p;
}

void spfa(Edge *(*a))
{
    memset(vis,false,sizeof(vis));
    for (int i = min1; i <= max1; i++) dis[i] = -inf;
    dis[min1] = 0;
    queue<int> q;
    q.push(min1);
    while(!q.empty())
    {
        int t = q.front();q.pop();
        vis[t] = false;
        for ( Edge *p = a[t];p; p = p->next)
        {
            int v = p->v, w = p->w ;
            if(dis[v] < dis[t]+p->w)
            {
                dis[v] = dis[t] + p->w;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }

        }
    }
    //for (int i = 1; i <= 11; i++) cout << dis[i] << endl;

}

int main()
{

    int x, y, z;
    while(scanf("%d",&n)!=EOF)
    {
        cnt = 0;
        memset(adj,NULL,sizeof(adj));
        max1 = -1, min1 = inf;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            addedge(x, y+1 ,z);
            min1 = min(min1,x);
            max1 = max(max1,y+1);
        }
        for (int i = min1; i < max1; i++)
        {
            addedge(i,i+1,0);
            addedge(i+1,i,-1);
        }
       spfa(adj);
       printf("%d\n",dis[max1]);
    }
    return 0;
}
