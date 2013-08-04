#include<iostream>
#define inf 1000000
using namespace std;
int map[1000][1000],dis[1000],vis[1000];
int n, m,i,j,start,end;
void Dijkstra()
{
    int i,j,min,k;
    for (i = 0; i < n; i++)
    {
        dis[i] = map[start][i];
    }
    dis[start] = 0;
    vis[start] = 1;
    for (i = 0; i < n; i++)
    {
        min = inf;
        for (j = 0; j < n; j++)
        {
            if(vis[j] == 0 && dis[j] < min)
            {
                min = dis[j];
                k = j;
            }
        }
        if(min == inf) break;
        vis[k] = 1;
        for (j = 0; j < n; j++)
        {
            if(vis[j] == 0 && dis[j] > dis[k] + map[k][j])
            {
                dis[j] = dis[k]+map[k][j];
            }
        }

    }

}
int main()
{
    int a,b,c;
    while (cin >> n >> m)
    {
        for (i = 0; i < n; i++)
        {
            dis[i] = inf;
            vis[i] = 0;
            for (j = 0; j < n; j++)
            {
                if(i == j) map[i][j] = map[j][i] = 0;
                else map[i][j] = map[j][i] = inf;
            }
        }
        for (i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            if (map[a][b] > c) map[a][b] = map[b][a] = c;
        }
        cin >> start >> end;
        Dijkstra();

        if (dis[end] < inf ) cout << dis[end] << endl;
        else cout << -1 << endl;
    }
    return 0;
}
