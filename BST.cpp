#include <iostream>
#include <cstdio>
#define nil 0
#define maxn 10006
using namespace std;

int key[maxn], left1[maxn], right1[maxn];
int p[maxn];
int root, node;

void Print(int x)
{
    if(x != nil)
    {
        Print(left1[x]);
        printf("%d",key[x]);
        Print(right1[x]);
    }
}

int Search(int x, int k)
{
    if(x == nil || k == key[x])
        return x;
    if(k < key[x])
        return Search(left1[x], k);
    else
        return Search(right1[x], k);
}

int Iterative_Search(int x, int k)
{
    while(x != nil && k != key[x])
    {
        if(k < key[x])
            x = left1[x];
        else
            x = right1[x];
    }
    return x;
}

int Minimum(int x)
{
    while(left1[x] != nil)
        x = left1[x];
    return x;
}

int Maximum(int x)
{
    while(right1[x] != nil)
        x = right1[x];
    return x;
}

int Successor(int x)
{
    if(right1[x] != nil)
        return Minimum(right1[x]);
    int y = p[x];
    while(y != nil && x == right1[y])
    {
        x = y;
        y = p[y];
    }
    return y;
}

int Predecessor(int x)
{
    if(left1[x] != nil)
        return Maximum(left1[x]);
    int y = p[x];
    while(y != nil && x == left1[y])
    {
        x = y;
        y = p[y];
    }
    return y;
}

void Insert(int &T, int v)
{
    if(T == nil)
        key[T = ++node] = v;
    else if(v <= key[T])
    {
        p[ left1[T] ] = T;
        Insert(left1[T], v);
    }
    else
    {
        p[ right1[T] ] = T;
        Insert(right1[T], v);
    }
}
void Iterative_Insert(int T, int v)
{
    int y = nil;
    int x = T;
    int z = ++node;
    key[z] = v;
    while(x != nil)
    {
        y = x;
        if(key[z] < key[x])
            x = left1[x];
        else
            x = right1[x];
    }
    p[z] = y;
    if(y == nil)
        key[T] = z;
    else if(key[z] < key[y])
        left1[y] = z;
    else
        right1[y] = z;
}

void Transplant(int T, int u, int v)
{
    if(p[u] == nil)
        T = v;
    else if(u == left1[p[u]])
        left1[p[u]] = v;
    else
        right1[p[u]] = v;
    if(v != nil)
        p[v] = p[u];
}

void Delete(int T, int z)
{
    if(left1[z] == nil)
        Transplant(T, z, right1[z]);
    else if(right1[z] == nil)
        Transplant(T, z, left1[z]);
    else
    {
        int y = Minimum(right1[z]);
        if(p[y] != z)
        {
            Transplant(T, y, right1[y]);
            right1[y] = right1[z];
            p[ right1[y] ] = y;
        }
        Transplant(T, z, y);
        left1[y] = left1[z];
        p[left1[y]] = y;
    }
}

void printarrs()
{
    printf("\ti\tkey\tleft\tright\tp\n");
    for (int i = 1; i <= node; i++)
    {
        printf("\t%d\t%d\t%d\t%d\t%d\n",
               i,key[i],left1[i],right1[i],p[i]);
    }
}

int main()
{
    int m[] = {3, 4, 5, 6, 7, 1};
    for (int i = 0; i < 6; i++)
    {
        Insert(root, m[i]);
        printf("Insert: %d",m[i]);
        printarrs();
        Print(root);
        printf("\n");
    }

    printf("Delete : 4");

    Delete(root, Search(root, 4));
    printarrs();
    Print(root);
    printf("\n");
    printf("5's successor's :pointer%d\n", Successor(Search(root, 5)));
    printf("5's Predecessor's :pointer%d\n", Predecessor(Search(root, 5)));
    return 0;
}
