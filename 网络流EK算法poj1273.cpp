#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define maxn 206
#define inf 0x3f3f3f3f
using namespace std;

int n, m;
int flow[maxn], pre[maxn], a[maxn][maxn];

int bfs(int source, int sink)
{
    queue<int> q;
    memset(pre, -1, sizeof(pre));
    pre[source] = 0;
    flow[source] = inf;
    q.push(source);
    while(!q.empty())
    {
        int id = q.front();
        if(id == sink) break;
        q.pop();
        for (int i = 2; i <= m; i++)
        {
            if(pre[i] != -1 || a[id][i] <= 0) continue;
            pre[i] = id;
            flow[i] = min(flow[id], a[id][i]);
            q.push(i);
        }
    }
    if(pre[sink] == -1) return -1;
    return flow[sink];
}
int maxflow(int source, int sink)
{
    int sum = 0, inc = 0;
    while((inc = bfs(source, sink)) != -1)
    {
        int s = sink;
        while(s != source)
        {
            int p = pre[s];
            a[p][s] -= inc;
            a[s][p] += inc;
            s = p;
        }
        sum += inc;
    }
    return sum;
}
int main()
{
    int x, y, z;
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y >> z;
            if(x==y) continue;
            a[x][y] += z;
        }
        cout << maxflow(1, m) << endl;
    }
    return 0;
}
