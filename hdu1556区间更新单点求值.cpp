#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define maxn 100006
using namespace std;

int tree[maxn], n;

int read(int pos)
{
    int ans = 0;
    while(pos > 0)
    {
        ans += tree[pos];
        pos -= (pos & -pos);
    }
    return ans;
}
void update(int pos, int val)
{
    while(pos <= n)
    {
        tree[pos] += val;
        pos += (pos&-pos);
    }
}
int main()
{
    //freopen("in.in","r",stdin);
    int x, y;
    while(~scanf("%d",&n))
    {
        if(!n)break;
        memset(tree,0,sizeof(tree));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d",&x,&y);
            update(x,1);
            update(y+1,-1);
        }
        for (int i = 1; i < n; i++)
        {
            cout << read(i) << " ";
        }
        cout << read(n);
        cout << endl;
    }
    return 0;
}
