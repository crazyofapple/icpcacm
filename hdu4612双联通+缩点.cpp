#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 200100
#define MAXM 2000100

struct node
{
    int v, w, pre;
} edge[MAXM];
int pos[MAXN], nEdge; //图的存储：链式前向星（池子法）

struct Bridge
{
    int u, v;
} bridge[MAXM];  //用来记录桥
int tot; //桥的个数

int fa[MAXN], cc; //fa：各个点所属的缩点（连通块），cc连通块的个数
int dfn[MAXN], low[MAXN], time;
int stack[MAXN], top;   //用于维护连通块的
int N,M;

void connect(int u, int v)
{
    edge[nEdge].pre = pos[u];
    edge[nEdge].v = v;
    pos[u] = nEdge;
    nEdge++;
}

void tarjan(int cur, int from)
{
    low[cur] = dfn[cur] = time++;
    stack[++top] = cur;
    for (int p=pos[cur]; p!=-1; p=edge[p].pre)
    {
        int v = edge[p].v;
        if (p == (from^1)) continue;  //注意一下这里
        if (!dfn[v])
        {
            tarjan(v, p);
            if (low[v] < low[cur]) low[cur] = low[v];

            if (low[v] > dfn[cur])
            {
                bridge[tot].u = cur;
                bridge[tot++].v = v;
                cc++;
                do
                {
                    fa[stack[top]] = cc;
                }
                while (stack[top--] != v);
            }
        }
        else
        {
            low[cur] = min(low[cur],dfn[v]);
        }
    }
}

vector<int> g[MAXN];
int vis[MAXN];
int get_r()
{
    int i,j;
    queue<int> q1;
    q1.push(1);
    memset(vis,0,sizeof(vis));
    int cur,pre;
    vis[1]=1;
    int temp;
    while(!q1.empty())
    {
        pre=q1.front();
        q1.pop();
        temp=pre;
        for(i=0;i<g[pre].size();i++)
        {
            int cur=g[pre][i];
            if(vis[cur]) continue;
            vis[cur]=1;
            q1.push(cur);
        }
    }

    queue<pair<int,int> > q2;
    memset(vis,0,sizeof(vis));
    q2.push(make_pair(temp,0));
    vis[temp]=1;
    pair<int,int> x,y;
    int res=0;
    while(!q2.empty())
    {
        x=q2.front();
        q2.pop();
        for(i=0;i<g[x.first].size();i++)
        {
            int cur=g[x.first][i];
            if(vis[cur]) continue;
            vis[cur]=1;
            q2.push(make_pair(cur,x.second+1));
            res=max(res,x.second+1);
        }
    }
    return res;
}
int main()
{
 //   freopen("input.txt","r",stdin);
    while(scanf("%d %d", &N, &M)==2&&N+M)
    {
        memset(pos, -1, sizeof(pos));
        nEdge = 0;
        int u, v, w;
        int i,j;
        for (i=0; i<M; i++)
        {
            scanf("%d%d", &u, &v);
            connect(u, v);
            connect(v, u);
        }

        memset(dfn, 0, sizeof(dfn));
        memset(fa, -1, sizeof(fa));

        cc = tot = 0;
        for (i=1; i<=N; i++)   //可以处理不连通的无向图，如果连通只需要一次即可
            if (!dfn[i])
            {
                top = time = 1;
                tarjan(i, -1);
                ++cc;
                for (j=1; j<=N; j++)   //特殊处理顶点的连通块
                    if (dfn[j] && fa[j]==-1) fa[j] = cc;
            }
        for(i=1;i<=N;i++)
        {
            g[i].clear();
        }
        for (int i=0; i<tot; i++)
        {
            int x,y;
            x=fa[bridge[i].u];
            y=fa[bridge[i].v];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int ans=tot-get_r();
        printf("%d\n",ans);

    }
    return 0;
}
