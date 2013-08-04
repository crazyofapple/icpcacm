/*我觉得有的时候就不能憨做题，然后记，应该知道为什么这样


一个顶点u是割点，当且仅当满足(1)或(2) (1) u为树根，且u有多于一个子树。
(2) u不为树根，且满足存在(u,v)为树枝边(或称父子边，即u为v在搜索树中的父亲)，使得DFS(u)<=Low(v)。

一条无向边(u,v)是桥，当且仅当(u,v)为树枝边，且满足DFS(u)<Low(v)。



当且仅当节点u满足如下两个条件之一时，u为割点：
    1.u为dfs树的根，且u至少有两个子节点。
    2.u不是dfs树的根，至少存在一个节点v是u的子节点，且low[v]>=dfn[u]。*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define maxn 1006
using namespace std;

struct Edge
{
    int v;
    int next;
}e[maxn*maxn];

int dfn[maxn],low[maxn],mark[maxn];
int adj[maxn],cnt,max1;


void addedge(int u, int v)
{
    e[cnt].v=v;
    e[cnt].next=adj[u];
    adj[u]=cnt++;
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++index;
    for (int t = adj[u]; t != -1; t=e[t].next)
    {
        int v=e[t].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<=low[v]) ///这个表示v的最深的祖先还比u的深度还要深
            {
                mark[u]++;
            }
        }
        else
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
}
int main()
{
    int x, y, ncase=0;
    while(~scanf("%d",&x))
    {
        if(x==0)break;
        max1=-1;
        scanf("%d",&y);
        memset(dfn,0,sizeof(dfn));
        memset(adj,-1,sizeof(adj));
        fill(mark,mark+1002,1);
        mark[1]=0;///1为根节点，所以我让他的连通度致0
        cnt=0;max1=max(x,y);
        addedge(x,y);addedge(y,x);
        while(~scanf("%d",&x))
        {
            if(x==0)break;
            scanf("%d",&y);
            max1=max(max1,max(x,y));
            addedge(x,y);addedge(y,x);
        }
        tarjan(1);///1为根节点

        bool flag=false;
        printf("Network #%d\n",++ncase);
        for (int i = 1; i <= max1; i++)
        {
            if(mark[i]>1)
            {
                flag=true;
                printf("  SPF node %d leaves %d subnets\n",i,mark[i]);
            }
        }
        if(!flag)
        {
           printf("  No SPF nodes\n");
        }
        cout << endl;
    }
    return 0;
}
