//#include <iostream>
//#include <cstdio>
//#include <queue>
//#include <cstring>
//#define inf 0x3f3f3f3f
//using namespace std;
//
//int n, m;
//int map[106][106],dis[106];
//int x,y,v;
//bool vis[106];
//
//void spfa()
//{
//    memset(vis, false, sizeof(vis));
//    for (int i = 1; i <= n; i++)
//    {
//        dis[i] = inf;
//    }
//    dis[1] = 0;
//    queue<int> q;
//    q.push(1);
//    while(!q.empty())
//    {
//        int t = q.front();q.pop();
//        vis[t] = false;
//        for (int i = 2; i <= n; i++)
//        {
//            if(dis[i] > dis[t]+map[t][i])
//            {
//                dis[i] = dis[t]+map[t][i];
//                if(!vis[i])
//                {
//                    vis[i] = true;
//                    q.push(i);
//                }
//            }
//        }
//    }
//    cout << dis[n] << endl;
//}
//int main()
//{
//    while (cin >> n >> m)
//    {
//        if(n==0&&m==0) break;
//        for (int i = 0; i <= n; i++)
//        {
//            map[i][i] = 0;
//            for (int j = i+1; j <= n; j++)
//            {
//                map[i][j] = map[j][i] = inf;
//            }
//        }
//        for (int i = 1; i<= m; i++)
//        {
//            cin >> x >> y >> v;
//            map[x][y] = map[y][x] = v;
//        }
//        spfa();
//    }
//    return 0;
//}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define maxn 1000006
#define inf 0x3f3f3f3f
using namespace std;

int n, m;
long long ans,cnt,cnt2,dis[maxn],dis2[maxn];
bool vis[maxn];


struct Edge
{
    int v;
    int w;
    Edge *next;
}*adj[maxn],e[maxn],*adj2[maxn],e2[maxn];
void addedge(int u, int v, int w)
{
    Edge *p = &e[cnt++];
    p->v = v; p->w = w; p->next=adj[u];adj[u]=p;
}
void addedge2(int u, int v, int w)
{
    Edge *p = &e2[cnt2++];
    p->v = v; p->w = w; p->next=adj2[u];adj2[u]=p;
}
void spfa(Edge *(*a))
{
    memset(vis,false,sizeof(vis));
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int t = q.front();q.pop();
        vis[t] = false;
        for (Edge *p= a[t]; p; p=p->next)
        {
            int v= p->v;
            if( dis[v] > dis[t]+p->w  )
            {
                dis[v] = dis[t]+p->w;
                if(!vis[v])
                {
                    vis[v]= true;
                    q.push(v);
                }
            }
        }
    }
    cout << dis[n] << endl;
}
void spfa2(Edge *(*a))
{
    memset(vis,false,sizeof(vis));
    for (int i = 1; i <= n; i++) dis2[i] = inf;
    dis2[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int t = q.front();q.pop();
        vis[t] = false;
        for (Edge *p= a[t]; p; p=p->next)
        {
            int v= p->v, w= p->w;
            if( dis2[v] > dis2[t]+p->w  )
            {
                dis2[v] = dis2[t]+p->w;
                if(!vis[v])
                {
                    vis[v]= true;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    int x, y, v;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        cnt=0;ans=0;cnt2=0;
        memset(adj,NULL,sizeof(adj));
        memset(adj2,NULL,sizeof(adj2));
        if(!m&&!n) break;
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y >> v;
            addedge(x,y,v);
           // addedge2(y,x,v);
        }
        spfa(adj);
//        for (int i = 1; i <= n; i++)
//        {
//            ans += dis[i];
//        }
//        spfa2(adj2);
//        for (int i = 1; i <= n; i++)
//        {
//            ans += dis2[i];
//        }
//        cout << ans << endl;
    }
    return 0;
}
//#include <iostream>
//#include <cstdio>
//#include <queue>
//#include <cstring>
//#define inf 0x3f3f3f3f
//#define maxn 1006*20
//using namespace std;
//
//int n, m1, m2, a, b, c, cnt;
//bool vis[maxn];
//int dis[maxn],p[maxn],adj[maxn];
//
//struct Edge
//{
//    int v;
//    int w;
//    int next;
//}node[maxn];
//
//void addedge(int u, int v, int w)
//{
//    node[cnt].v = v;
//    node[cnt].w = w;
//    node[cnt].next = adj[u];
//    adj[u] = cnt++;
//}
//bool spfa()
//{
//    memset(vis,false,sizeof(vis));
//    for (int i = 1; i <= n; i++) dis[i] = inf;
//    dis[1] = 0;
//    queue<int> q;
//    q.push(1);
//    while(!q.empty())
//    {
//        int t = q.front();q.pop();
//        vis[t] = false;
//        for (int i = adj[t]; i != -1; i=node[i].next)
//        {
//            int v= node[i].v;
//            int w=node[i].w;
//            if(dis[v]>dis[t]+w)
//            {
//                dis[v] = dis[t]+w;
//                if(!vis[v])
//                {
//                    vis[v]=true;
//                    q.push(v);
//                  if((++p[v])>n) return false; //这里要用sqrt（n）
//                }
//
//            }
//        }
//    }
//    return true;
//}
//int main()
//{
//    memset(adj,-1,sizeof(adj));
//    scanf("%d%d%d",&n,&m1,&m2);
//    for (int i = 1; i <= m1; i++)
//    {
//        scanf("%d%d%d",&a,&b,&c);
//        addedge(a,b,c);
//    }
//    for (int i = 1; i <= m2; i++)
//    {
//        scanf("%d%d%d",&a,&b,&c);
//        addedge(b,a,-c);
//    }
//    for (int i =2; i <= n; i++)
//    {
//        addedge(i,1,0);
//        addedge(i,i-1,0);
//    }
//    if(spfa())
//    {
//        if(dis[n] == inf)
//        {
//            printf("-2\n");
//        }
//        else
//        {
//            printf("%d\n",dis[n]);
//        }
//    }
//    else
//    {
//        printf("-1\n");
//    }
//    return 0;
//}
