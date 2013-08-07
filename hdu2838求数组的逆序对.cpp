#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 100006
using namespace std;

struct node
{
    int cnt;
    __int64 sum;
}tree[maxn];
int n;
void update(int pos, int x)
{
    while(pos <= n)
    {
        tree[pos].sum+=x;
        tree[pos].cnt++;
        pos+=(pos&-pos);
    }
}
__int64 query(int pos)
{
    __int64 ans = 0;
    while(pos>0)
    {
        ans+=tree[pos].cnt;
        pos-=(pos&-pos);
    }
    return ans;
}
__int64 query2(int pos)
{
    __int64 sum = 0;
    while(pos > 0)
    {
        sum+=tree[pos].sum;
        pos-=(pos&-pos);
    }
    return sum;

}
int main()
{
    while(~scanf("%d",&n))
    {
        int x;
        __int64 ans = 0;
        memset(tree, 0, sizeof(tree));
        for (int i = 1; i <= n ;i++)
        {
            scanf("%d",&x);
            update(x, x);
            __int64 k = i - query(x);//da
            if(k > 0)
            {
                __int64 t = query2(n) - query2(x);
                ans+=k*x+t;
            }
        }
        cout << ans <<endl;
    }
    return 0;
}

