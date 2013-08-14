#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#define maxn 100006
using namespace std;

struct Edge
{
    int v;
    int next;
} e[maxn];

int n, m;
int dfn[maxn], low[maxn], id[maxn],in[maxn],out[maxn];
int cnt, adj[maxn], ans,index, num;
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
