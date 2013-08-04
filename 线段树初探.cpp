#include<iostream>
using namespace std;
struct Tree
{
    int left,right;
    int sum,max;
} tree[4000];
int a[100];
void build(int id, int l, int r) //build (1,1,n)
{
    tree[id].left = l;
    tree[id].right = r;
    if (l == r)
    {
        tree[id].sum = tree[id].max = a[l];
    }
    else
    {
        int mid = (l + r) / 2;
        build(2*id+1,mid+1,r);
        build(2*id,l,mid);
        tree[id].sum = tree[2*id].sum + tree[2*id+1].sum;
        tree[id].max = max(tree[2*id].max, tree[2*id+1].max);
    }
}
void update(int id, int pos, int val) //update (1,k,val)
{
    if (tree[id].left == tree[id].right)
    {
        tree[id].max = tree[id].sum = val;
    }
    else
    {
        int mid = (tree[id].left + tree[id].right) / 2;
        if (pos <= mid) update(2*id, pos, val);
        else update(2*id + 1, pos, val);
        tree[id].sum = tree[2*id].sum + tree[2*id+1].sum;
        tree[id].max = max(tree[2*id].max, tree[2*id+1].max);
    }
}
int query(int id, int l, int r) //query (1,1,n)
{
    if (tree[id].left == l && tree[id].right == r)
    {
        return tree[id].sum;
    }
    else
    {
        int mid = (tree[id].left + tree[id].right)/2;

        if (r<=mid) return query(id*2,l,r);
        else if (l>mid) return query(id*2+1,l,r);
        else
            return query(id*2,l,mid)+query(id*2+1,mid+1,r);

    }

}

int main()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1,1,n);
    cout << query(1,2,n) << endl;
    //10 1 2 3 4 5 6 7 8 9 0
}
