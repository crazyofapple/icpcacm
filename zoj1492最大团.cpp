#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define maxn 106
using namespace std;

int ans;
int n, m;
int can[maxn][maxn], tuan[maxn], map[maxn][maxn];
int num[maxn], x[maxn];

bool dfs(int tot, int cnt)
{
    if(tot == 0)
    {
        if(cnt > ans)
        {
            ans = cnt;
            for (int i = 0; i < ans; i++)
            {
                tuan[i]=x[i];
            }
            return true;
        }
        return false;
    }
    for (int i = 0; i < tot; i++)
    {
        if(cnt + (tot - i) <= ans) return false;
        if(cnt + num[ can[cnt][i] ] <= ans) return false;
        int k = 0;
        x[cnt] = can[cnt][i];
        for (int j = i + 1;  j < tot; j++)
        {
            if(map[ can[cnt][i] ][ can[cnt][j] ])
            {
                can[cnt+1][k++] = can[cnt][j];
            }
        }
        if (dfs(k, cnt+1)) return false;
    }
    return false;
}
void maxtuan()
{
    for (int i = n; i >= 1; i--)
    {
        int k=0;x[0]=i;
        for (int j = i + 1; j <= n; j++)
        {
            if(map[i][j])
            {
                can[1][k++] = j;
            }
        }
        dfs(k,1);
        num[i]=ans;
    }
}
int main()
{
    while(cin >> n)
    {
        if(n==0) break;
        ans=0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> map[i][j];
            }
        }
        maxtuan();
        cout << ans << endl;
    }
    return 0;
}

