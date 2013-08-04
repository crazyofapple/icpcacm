#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define maxn 50006
using namespace std;

struct Tree
{
    int left, right;
    int ma;
    int mi;
} tree[4*maxn];
int n, q, h[maxn];


void build(int id, int l, int r)
{
    tree[id].left = l;
    tree[id].right = r;
    if(l == r)
    {
        tree[id].ma=tree[id].mi=h[l];
    }
    else
    {
        int mid = (l+r)/2;
        build(2*id+1, mid+1, r);
        build(2*id, l, mid);
        tree[id].ma=max(tree[2*id].ma, tree[2*id+1].ma);
        tree[id].mi=min(tree[2*id].mi, tree[2*id+1].mi);

    }
}
int findmax(int id, int l, int r)
{
    if (tree[id].left == l && tree[id].right == r)
    {
        return tree[id].ma;
    }
    else
    {
        int mid = (tree[id].left + tree[id].right)/2;

        if (r<=mid) return findmax(id*2,l,r);
        else if (l>mid) return findmax(id*2+1,l,r);
        else
            return max(findmax(id*2,l,mid),findmax(id*2+1,mid+1,r));

    }

}
int findmin(int id, int l, int r)
{
    if (tree[id].left == l && tree[id].right == r)
    {
        return tree[id].mi;
    }
    else
    {
        int mid = (tree[id].left + tree[id].right)/2;

        if (r<=mid) return findmin(id*2,l,r);
        else if (l>mid) return findmin(id*2+1,l,r);
        else
            return min(findmin(id*2,l,mid),findmin(id*2+1,mid+1,r));

    }

}
int main()
{
    int x, y, min1, max1;
    while(~scanf("%d%d", &n, &q))
    {
        memset(h,0,sizeof(h));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d",&h[i]);
        }
        build(1,1,n);
        while(q--)
        {
            scanf("%d%d",&x,&y);
            max1 = findmax(1, x, y);
            min1 = findmin(1, x, y);
            printf("%d\n", max1-min1);
        }
    }
    return 0;
}
