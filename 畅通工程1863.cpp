#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define maxn 106
using namespace std;

struct edge
{
    int s, e, w;
}e[maxn];
int bin[maxn];
int findx(int x) {return bin[x] == x ? x : bin[x] = findx(bin[x]);}

int main()
{
    int n, m, ans;
    while(cin >> n >> m)
    {
        if(!n)break;
        ans = 0;
        for (int i = 1; i <= m; i++) bin[i] = i;
        for (int i = 1; i <= n; i++)
        {
            cin >> e[i].s >> e[i].e >> e[i].w;
        }
        for (int i = 1; i <= n; i++)
        {
            int fx = findx(e[i].s);
            int fy = findx(e[i].e);
            if(fx!=fy)
            {
                bin[fy] = fx;
                ans += e[i].w;
            }
        }
        bool flag = false;
        for (int i = 1; i <= m; i++)
        {
            if(findx(i) != findx(1))
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            cout << "?" << endl;
        }
        else
        {
            cout << ans << endl;

        }
    }
    return 0;
}
