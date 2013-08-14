///时间复杂度O（n+m）
///其实visit可以不用
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <vector>
#include <string>
#define maxn 10006
#define pb push_back
using namespace std;
vector<int> g[maxn];
stack<int> st;
int  dfn[maxn],index,cnt,low[maxn],visit[maxn];
int  instack[maxn],num,ans1[maxn];
void tarjan(int u)
{
    dfn[u]=low[u]=++index;
    st.push(u);
    instack[u]++;
    visit[u]=true;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(!visit[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        int v;
        do
        {
            v=st.top();
            instack[v]=0;
            st.pop();
        }while(u!=v);
        num++;
    }
}
int main()
{
    int n, m, x, y;
    while(cin >> n >> m)
    {
        if(!n&&!m)break;
        for (int i = 0; i <= n; i++){g[i].clear();}
        memset(visit,false,sizeof(visit));
        memset(instack,0,sizeof(instack));
        index=0;num=0;
        for (int i = 0; i <m; i++)
        {
            scanf("%d%d",&x,&y);
            g[x].pb(y);
        }
        for (int i = 1; i <= n; i++)
        {
            if(!visit[i])tarjan(i);
        }
        cout << num << endl;
        cout << endl;
    }
    return 0;
}
