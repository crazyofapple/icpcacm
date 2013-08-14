#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define maxn 100010
using namespace std;

struct Tree
{
    int left;
    int right;
    int sum;
    bool cover;
} tree[maxn*4];

int n,m,ans,q;
int fun(int x)
{
    int ans = 0;
    while(x)
    {
        if(x%2) ans++;
        x/=2;
    }
    return ans;
}
void build(int id, int l, int r)
{
    tree[id].left = l;
    tree[id].right = r;
    tree[id].sum = (1<<1);
    tree[id].cover = true;
    if(l==r)return;
    int mid = (l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
}
void update(int id, int l, int r, int val)
{
    if(l<=tree[id].left && r>=tree[id].right)
    {
        tree[id].cover=true;
        tree[id].sum = (1<<val);
        return;
    }
    if(tree[id].left==tree[id].right)return;
    if(tree[id].cover)
    {
        tree[2*id].cover = true;
        tree[2*id+1].cover = true;
        tree[2*id].sum=tree[id].sum;
        tree[2*id+1].sum=tree[id].sum;
        tree[id].cover = false;
    }
    int mid=(tree[id].left+tree[id].right)>>1;
    if(l > mid) update(2*id+1,l,r,val);
    else if(r <= mid) update(2*id,l,r,val);
    else
    {
        update(2*id, l,mid,val);
        update(2*id+1,mid+1,r,val);
    }
    tree[id].sum=tree[2*id].sum|tree[2*id+1].sum;
}
int query(int id, int l, int r)
{
    if(l==tree[id].left && r==tree[id].right)
    {
        return tree[id].sum;
    }
    if(tree[id].cover)
    {
        tree[2*id].cover = true;
        tree[2*id+1].cover = true;
        tree[2*id].sum=tree[id].sum;
        tree[2*id+1].sum=tree[id].sum;
        tree[id].cover = false;
    }
    if(tree[id].left != tree[id].right)
    {
        int mid=(tree[id].left+tree[id].right)>>1;
        if(r<=mid) return query(2*id, l, r);
        else if(l>mid) return query(2*id+1,l,r);
        else
        {
            return query(2*id,l,mid)|query(2*id+1,mid+1,r);
        }
    }
}
int main()
{
    int x, y, z;
    string str;
    while(~scanf("%d%d%d",&n,&m,&q))
    {
        memset(tree,0,sizeof(tree));
        build(1,1,n);
        while(q--)
        {
            cin >> str;
            if(str=="C")
            {
                scanf("%d%d%d",&x,&y,&z);
                if(x>y) swap(x,y);
                update(1,x,y,z);
            }
            else if(str == "P")
            {
                scanf("%d%d",&x, &y);
                if(x>y)swap(x,y);
                printf("%d\n",fun( query(1,x,y) ));
            }
        }
    }
    return 0;
}
