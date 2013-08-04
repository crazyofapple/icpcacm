#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#define root T
using namespace std;

int t, ans, cnt, n;
char str[1000006];
struct node
{
    int cnt;
    node *nt[26];
    node *fail;
    void init()
    {
        memset(nt, NULL, sizeof(nt));
        cnt = 0; fail = NULL;
    }
}T[1000006];
void insert(char *str1)
{
    node *p = root;
    int tmp = strlen(str1);
    for (int i = 0; i < tmp; i++)
    {
        int k = str1[i] - 'a';
        if(p->nt[k] == NULL)
        {
            T[cnt].init();
            p->nt[k] = &T[cnt];
            cnt++;
        }
        p = p->nt[k];
    }
    p->cnt++;
}
void build_fail()
{
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *father = q.front(); q.pop();
        for (int i = 0; i < 26; i++)
        {
            if(father->nt[i])
            {
                node *tmp = father->fail;
                while(tmp &&  tmp->nt[i] == NULL) tmp = tmp->fail;
                if(tmp) father->nt[i]->fail = tmp->nt[i];
                else father->nt[i]->fail = root;
                q.push(father->nt[i]);
            }

        }
    }
}
int query(char *str1)
{
    node *p = root, *tmp;
    while (*str1)
    {
        int k = *str1 - 'a';
        while ( p->nt[k] == NULL && p != root)
        {
            p = p->fail;
        }
        p = p->nt[k];
        if(p == NULL) p = root;
        node *tmp = p;
        while (tmp != root && tmp->cnt != -1)
        {
            ans += tmp->cnt;
            tmp->cnt = -1;
            tmp = tmp->fail;
        }
        str1++;
    }
    return ans;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cnt = 1; ans = 0;
        T[0].init();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", str);
            insert(str);
        }
        build_fail();
        scanf("%s", str);
        printf("%d\n", query(str));
    }
    return 0;
}
