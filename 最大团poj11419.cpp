#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, map[105][105];
int ans, cnt, opt[105], st[105];

void dfs(int now)
{
    if (now > n)   // 如果枚举了所有的节点
    {
        ans = cnt;
        memcpy(opt, st, sizeof (st)); // 用一个更大的极大团替代原有的极大团
        return;
    }
    bool flag = true;
    for (int i = 1; i < now; ++i)   // 检测新加入的点是否到团中的其他节点都存在一条边
    {
        if (st[i] && map[i][now])
        {
            flag = false;
            break;
        }
    }
    if (flag)   // 如果该节点满足在这个团中
    {
        st[now] = 1, ++cnt; // 该节点被加入到完全子图中去
        dfs(now + 1);
        st[now] = 0, --cnt;
    }
    if (cnt+n-now > ans)   // 跳过x节点进行搜索同时进行一个可行性判定
    {
        dfs(now + 1);
    }
}

int main()
{
    int ncase, x, y;
    scanf("%d", &ncase);
    while (ncase--)
    {
        ans = cnt = 0;
        scanf("%d%d", &n, &m);
        memset(st, 0, sizeof (st));
        memset(map,0, sizeof(map));
        while (m--)
        {
            scanf("%d%d", &x, &y);
            map[x][y] = map[y][x] = 1;
        }
        dfs(1);
        printf("%d\n", ans);
        for (int i = 1, j = 0; i <= n; ++i)
        {
            if (opt[i])
            {
                printf(j == 0 ? "%d" : " %d", i);
                ++j;
            }
        }
        cout << endl;
    }
    return 0;
}
