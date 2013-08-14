#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#define maxn 20002
using namespace std;

struct Edge
{
    int v;
    int next;
} e[50002];

int cnt, adj[maxn];
int dfn[maxn], low[maxn], in[maxn], out[maxn], id[maxn];
bool instack[maxn];
int index, num, ans1, ans2;
int n, m;
stack<int > st;

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
    for (int t = adj[u]; t != -1; t = e[t].next)
    {
        int v=e[t].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
        {
            low[u]=min(low[u], dfn[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        num++;
        int v;
        do
        {
            v=st.top();
            instack[v]=false;
            id[v]=num;
            st.pop();
        }
        while(u!=v);
    }
}
int main()
{
    int ncase;
    int x, y;
    scanf("%d",&ncase);
    while(ncase--)
    {
        memset(adj, -1, sizeof(adj));
        memset(dfn, 0, sizeof(dfn));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(instack, false, sizeof(instack));
        memset(id, 0, sizeof(id));
        cnt=0;
        ans1=0;
        ans2=0;
        index=0;
        num=0;
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d",&x,&y);
            addedge(x, y);
        }
        for (int i = 1; i <= n; i++)
        {
            if(!dfn[i]) tarjan(i);
        }
        if(num == 1)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int t = adj[i]; t!=-1; t=e[t].next)
            {
                int v=e[t].v;
                if(id[i]!=id[v]) out[ id[i] ] ++, in[ id[v] ]++;
            }
        }
        for(int i = 1; i <= num; i++)
        {
            if(in[i] == 0)
            {
                ans1++;
            }
            if(out[i] == 0)
            {
                ans2++;
            }
        }
        printf("%d\n",max(ans1, ans2));
    }
    return 0;
}
