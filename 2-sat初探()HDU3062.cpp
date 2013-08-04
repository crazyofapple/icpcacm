#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <stack>
#define maxn 1006*2
using namespace std;

struct Edge
{
    int v;
    int next;
}e[maxn*maxn];
int n, m;

int adj[maxn], cnt;
int dfn[maxn], low[maxn],id[maxn];
bool instack[maxn];
int num,ans,index;
stack<int> st;

void addedge(int u, int v)
{
    e[cnt].v=v;
    e[cnt].next=adj[u];
    adj[u]=cnt++;
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++index;
    st.push(u);
    instack[u]=true;
    for (int t = adj[u]; t != -1; t=e[t].next)
    {
        int v=e[t].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u] == low[u])
    {
        num++;
        int v;
        do
        {
            v=st.top();
            instack[v]=false;
            id[v]=num;
            st.pop();
        }while(u!=v);
    }
}

int main()
{
    int a1,a2,c1,c2;
    while(~scanf("%d%d",&n,&m))
    {
        memset(adj,-1,sizeof(adj));
        memset(instack, false, sizeof(instack));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(id,0,sizeof(id));
        cnt=0;num=0;index=0;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d%d",&a1,&a2,&c1,&c2);
            addedge(a1*2+c1, a2*2+1-c2);
            addedge(a2*2+c2, a1*2+1-c1);
        }
        for (int i = 1; i <= 2*n; i++)
        {
            if(!dfn[i])tarjan(i);
        }
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if(id[i*2] == id[i*2+1])
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }

    }
    return 0;
}
