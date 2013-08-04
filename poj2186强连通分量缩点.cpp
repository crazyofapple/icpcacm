
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#define maxn 50006
#define maxn1 10006
using namespace std;
struct Edge
{
    int v;
    int next;
}e[maxn];
int adj[maxn1];
int dfn[maxn1], low[maxn1];
bool instack[maxn1];
int out[maxn1];
int id[maxn1];
stack<int> st;
int num,cnt,ans,index; //num = sum of scc

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
    instack[u] = true;
    for (int t = adj[u]; t != -1; t=e[t].next)
    {
        int v = e[t].v;
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
    if(low[u] == dfn[u])
    {
        num++;
        int v;
        do
        {
            v=st.top();
            st.pop();
            instack[v]=false;
            id[v]=num;
        }while(u!=v);
    }
}
int n, m;


int main()
{
    int x, y, p;
    while(cin >> n >> m)
    {
        memset(adj,-1,sizeof(adj));
        num=0;cnt=0;index=0;ans=0;
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(instack,false,sizeof(instack));
        memset(out,0,sizeof(out));
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            addedge(x,y);
        }
        for (int i = 1; i <= n; i++)
        {
            if(!dfn[i]) tarjan(i);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int t = adj[i]; t != -1; t = e[t].next)
            {
                int v = e[t].v;
                if(id[i] != id[v]) out[ id[i] ]  ++;
            }
        }
        for (int i = 1; i <= num; i++)
        {
            if(!out[i])
            {
                ans++;
                p=i;
            }
        }
        if(ans > 1)
        {
            cout << 0 << endl;
        }
        else
        {
            ans = 0;
            for (int i = 1; i <= n; i++)
            {
                if(p == id[i])
                {
                    ans++;
                }
            }
            cout << ans << endl;
        }

    }
    return 0;
}
