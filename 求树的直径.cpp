#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define maxn 100006
#define inf 0x3f3f3f3f
using namespace std;

struct Edge
{
    int v;
    int next;
}e[maxn*10];
int adj[maxn],cnt,dis[maxn],n,m;

void addedge(int u,int v)
{
    e[cnt].v = v;
    e[cnt].next = adj[u];
    adj[u]=cnt++;
}
void dfs(int now)
{
    for (int t = adj[now]; t != -1; t=e[t].next)
    {
        int k =e[t].v;
        if(dis[k]==-1)
        {
            dis[k]=dis[now]+1;
            dfs(k);
        }

    }
}
int main()
{
    int ncase;
    cin >> ncase;
    while(ncase--)
    {
        memset(adj,-1,sizeof(adj));
        cnt=0;
        scanf("%d%d",&n,&m);
        for (int i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            addedge(x,y);addedge(y,x);
        }
        memset(dis,-1,sizeof(dis));
        dis[1]=0;
        dfs(1);
        int max1=-inf,temp=0;
        for (int i = 1;i <= n; i++)
        {
            if(max1<dis[i])
            {
                max1=dis[i];temp=i;
            }
        }
        max1 = -inf;
        memset(dis,-1,sizeof(dis));
        dis[temp]=0;
        dfs(temp);
        for (int i = 1; i <= n; i++)
        {
            if(max1<dis[i])
            {
                max1=dis[i];
            }
        }
        max1++;
        while(m--)
        {
            int k;
            scanf("%d",&k);
            if(k<=max1)
            {
                printf("%d\n",k-1);
            }
            else{printf("%d\n",max1-1+(k-max1)*2);}
        }


    }
   return 0;
}
