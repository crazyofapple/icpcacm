#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 106
using namespace std;
struct Edge
{
    int s;
    int e;
    int w;
}e[maxn*maxn/2];
int bin[maxn];
int findx(int x) {return bin[x] == x ? x : bin[x] = findx(bin[x]);}
bool cmp(const Edge x, const Edge y)
{
    return x.w < y.w;
}
int main()
{
    int n,ans;
    while(~scanf("%d",&n))
    {
        if(!n)break;
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            bin[i] = i;
        }
        int num = n * (n-1) / 2;
        for (int i = 1; i <= num; i++)
        {
            cin >> e[i].s >> e[i].e >>e[i].w;
        }
        sort(e, e+num+1, cmp);
        for (int i = 1; i <= num; i++)
        {
            int fx = findx(e[i].s);
            int fy = findx(e[i].e);
            if(fx!=fy)
            {
                bin[fy] = fx;
                ans += e[i].w;
            }
        }
        cout  << ans << endl;
    }
    return 0;
}
