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
    if (now > n)   // ���ö�������еĽڵ�
    {
        ans = cnt;
        memcpy(opt, st, sizeof (st)); // ��һ������ļ��������ԭ�еļ�����
        return;
    }
    bool flag = true;
    for (int i = 1; i < now; ++i)   // ����¼���ĵ��Ƿ����е������ڵ㶼����һ����
    {
        if (st[i] && map[i][now])
        {
            flag = false;
            break;
        }
    }
    if (flag)   // ����ýڵ��������������
    {
        st[now] = 1, ++cnt; // �ýڵ㱻���뵽��ȫ��ͼ��ȥ
        dfs(now + 1);
        st[now] = 0, --cnt;
    }
    if (cnt+n-now > ans)   // ����x�ڵ��������ͬʱ����һ���������ж�
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
