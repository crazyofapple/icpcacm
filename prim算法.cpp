#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define inf 0x3f3f3f3f
using namespace std;

int n, t, min1,ans;
int dist[1006], map[106][106];

int prim()
{
    for (int i = 2; i <= n; i++)
    {
        dist[i] = map[1][i];
    }
    for (int i = 2; i <= n; i++)
    {
        min1 = inf; t = 0;
        for (int j = 2; j <= n; j++)
        {
            if(dist[j] < min1 && dist[j])
            {
                min1 = dist[j];
                t = j;
            }
        }
        ans += min1;
        dist[t] = 0;
        for (int j = 2; j <= n; j++)
        {
            if(dist[j] > map[t][j] && dist[j])
            {
                dist[j] = map[t][j];
            }
        }
    }
    return ans;
}
int main()
{
    int x, y, z;
    while(cin >> n)
    {
        if(!n) break;
        ans = 0;
        memset(map, inf, sizeof(map));
//        for (int i = 1; i <= n; i++)
//        {
//            for (int j = 1; j <= n; j++)
//            {
//                cin >> map[i][j];
//            }
//        }
        for (int i = 1; i <= n*(n-1)/2; i++)
        {
            cin >>x >> y >>z;
            map[x][y] = z;
        }
        cout << prim() << endl;
    }
    return 0;
}
