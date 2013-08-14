#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#define inf 0x3f3f3f3f
using namespace std;

int q, k;
int od, t;
struct node
{
    int x[6];
} p[60006];
multiset<int> mst[1<<5];

int main()
{
    freopen("in.in","r",stdin);
    while(~scanf("%d%d",&q,&k))
    {
        for (int i = 0; i < (1<<k); i++)
        {
            mst[i].clear();
        }
        for (int ii = 1; ii <= q; ii++)
        {
            scanf("%d",&od);
            int tt = 0, t = 0, sum = 0;
            if(od == 0)
            {
                for (int i = 1; i <= k; i++)
                {
                    scanf("%d",&p[ii].x[i]);
                }
                for (int j = 0; j < (1<<k); j++)
                {
                    t = j;
                    sum = 0;
                    for (int i = 1; i <= k; i++)
                    {
                        if(t&1)
                        {
                            sum += p[ii].x[i];
                        }
                        else
                        {
                            sum -= p[ii].x[i];
                        }
                        t>>=1;
                    }
                    mst[j].insert(sum);
                }
            }
            else if(od == 1)
            {
                cin >> tt;
                for (int j = 0; j < (1<<k); j++)
                {
                    t = j;
                    sum = 0;
                    for (int i = 1; i <= k; i++)
                    {
                        if(t&1)
                        {
                            sum += p[tt].x[i];
                        }
                        else
                        {
                            sum -= p[tt].x[i];
                        }
                        t>>=1;
                    }
                    multiset<int>::iterator it;
                    it=mst[j].find(sum);
                    mst[j].erase(it);
                }
            }
            int ans = -1;
            for (int i = 0; i < (1<<k); i++)
            {
                multiset<int>::iterator t1 = mst[i].begin();
                multiset<int>::iterator t2 = mst[i].end();
                t2--;
                ans = max(ans, *(t2)-(*t1));
            }
            cout << ans <<endl;
        }
    }
    return 0;
}
