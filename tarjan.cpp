#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
#define maxn 106
using namespace std;

struct Edge
{
    int v;
    int next;
} e[maxn*maxn];

int n, m;
int dfn[maxn], low[maxn], id[maxn], in[maxn],out[maxn];
int cnt, adj[maxn], ans1, index, num,ans2;
bool instack[maxn];
stack<int> st;

void addedge(int u, int v)
{
    e[cnt].v=v;
    e[cnt].next=adj[u];
    adj[u]=cnt++;
}
void tarjan(int u)
{
    dfn[u]=low[u]=++index;
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
        }
        while(u!=v);
    }
}
int main()
{
    int x;
    while (~scanf("%d",&n))
    {
        memset(adj, -1, sizeof(adj));
        memset(dfn,0,sizeof(dfn));
        memset(id,0,sizeof(id));
        memset(out,0,sizeof(in));
        memset(in,0,sizeof(in));
        memset(instack,false,sizeof(instack));
        cnt = 0;
        ans1 = 0;
        num = 0;
        index = 0;
        ans2 = 0;
        for (int i = 1; i <= n; i++)
        {
            while(1)
            {
                scanf("%d",&x);
                if(!x)break;
                addedge(i, x);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if(!dfn[i]) tarjan(i);
        }
        if(num == 1){cout << 1 << endl; cout << 0 << endl;continue;}
        for (int i = 1; i <= n; i++)
        {
            for (int t = adj[i]; t != -1; t = e[t].next)
            {
                int v = e[t].v;
                if(id[i] != id[v]) out[ id[i] ]  ++, in[ id[v] ]++;
            }
        }
        for (int i = 1; i <= num; i++)
        {
            if(in[i] == 0)
            {
                ans1++;
            }
            else if(out[i] == 0)
            {
                ans2++;
            }
        }
        cout << ans1 << endl;
        cout << max(ans1, ans2)<<endl;
    }
    return 0;
}
