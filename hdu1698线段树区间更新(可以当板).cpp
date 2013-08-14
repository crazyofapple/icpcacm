#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define maxn 100006
using namespace std;
///为什么比普通线段树快，是以为不用查到叶子节点
struct Tree
{
    int left;
    int right;
    int sum;
}tree[maxn*4];

int ans,n;
void build(int l, int r, int id)
{
    tree[id].left = l;
    tree[id].right = r;
    tree[id].sum = 1;
    if(l == r) return;
    int mid = (l+r)>>1;
    build(l, mid, 2*id);
    build(mid+1,r, 2*id+1);
}
void update(int id, int l, int r, int val)
{
    if(l == tree[id].left && r == tree[id].right)
    {
        tree[id].sum = val;
        return;
    }
    if(tree[id].left == tree[id].right) return;
    if(tree[id].sum > 0)
    {
        tree[2*id].sum = tree[id].sum;
        tree[2*id+1].sum = tree[id].sum;
        tree[id].sum = 0;
    }
    int mid = (tree[id].left + tree[id].right) >> 1;
    if(l > mid) update(2*id+1,l,r,val);
    else if(r <= mid) update(2*id,l,r,val);
    else
    {
        update(2*id, l,mid,val);
        update(2*id+1,mid+1,r,val);
    }
}
void query(int id, int l, int r)
{
    if(tree[id].sum > 0)
    {
        ans += tree[id].sum * (r-l+1);
        return;
    }
    if(tree[id].left == tree[id].right) return;
    int mid = (l+r)>>1;
    query(2*id,l,mid);
    query(2*id+1,mid+1,r);
}
int main()
{
    int ncase,q,cas=0;
    int x, y, z;
    scanf("%d",&ncase);
    while(ncase--)
    {
        cas++;
        memset(tree,0,sizeof(tree));
        scanf("%d",&n);
        build(1,n,1);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d%d",&x,&y,&z);
            update(1,x,y,z);
        }
        ans=0;
        query(1,1,n);
        printf("Case %d: The total value of the hook is %d.\n",cas,ans);
    }
    return 0;
}
