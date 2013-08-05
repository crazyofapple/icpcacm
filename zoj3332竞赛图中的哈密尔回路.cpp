#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int NN=110;

int n,map[NN][NN];

struct node
{
    int x;
    struct node *next;
}*h;

inline void clr(node *p)
{
    node *pp;
    while (p)
    {
        pp=p;
        p=p->next;
        delete(pp);
    }
}

inline bool ok(int i,int j,int k)
{
    return (map[i][j] && map[j][k]);
}
void solve()
{
    node *p1,*p2;
    clr(h);
    h=new node;
    h->x=0;
    h->next=NULL;

    for (int i=1; i<=n; i++)
    {
        p1=h;
        while (p1->next && !ok(p1->x,i,p1->next->x)) p1=p1->next;
        p2=new node;
        p2->x=i;
        p2->next=p1->next;
        p1->next=p2;
    }

    p1=h->next;
    for (int i=1; i<n; i++)
    {
        printf("%d ",p1->x);
        p1=p1->next;
    }
    printf("%d\n",p1->x);
}

int main()
{
    int cas,u,v;
    scanf("%d",&cas);
    while (cas--)
    {
        scanf("%d",&n);
        if (n==1)
        {
            printf("1\n");
            continue;
        }

        for (int i=1; i<=n; i++) map[0][i]=true;
        for (int i=1; i<=n*(n-1)/2; i++)
        {
            scanf("%d%d",&u,&v);
            map[u][v]=true;
            map[v][u]=false;
        }
        solve();
    }
    return 0;
}
