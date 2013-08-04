//author: crazyofapple poj 1659
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

struct node
{
    int index;
    int degree;
}nodes[16];

int edge[16][16];
bool flag;

int cmp(const void *a, const void *b)
{
    struct node *c = (struct node *)a;
    struct node *d = (struct node *)b;
    return c->degree <  d->degree ? 1 : -1;
}

int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> nodes[j].degree;
            nodes[j].index = j;
        }
        memset(edge, 0, sizeof(edge));
        flag = true;
        for (int j = 0; j < n && flag; j++)
        {
            qsort(nodes+j, n-j, sizeof(nodes[0]),cmp);
            int r = nodes[j].index;
            if(nodes[j].degree > n - j - 1)
                flag = false;
            int tmp = nodes[j].degree, s = 1, c;
            while(tmp && flag)
            {
                nodes[j+s].degree--;
                c = nodes[j+s].index;
                if(nodes[j+s].degree < 0) flag = false;
                else edge[r][c] = edge[c][r] = 1;
                s++;tmp--;
            }
        }
        if(!flag) printf("NO\n");
        else
        {
            printf("YES\n");
            for (int k = 0; k < n; k++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(j) printf(" ");
                    cout << edge[k][j] ;
                }
                cout << endl;
            }
        }
        if( i != t - 1) cout << endl;
    }
    return 0;
}
