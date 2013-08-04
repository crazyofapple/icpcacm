#include<iostream>
#include<algorithm>
using namespace std;
struct NODE
{
    int v,up;

} node[253];
int sum, ans, num,sum1,l,dp[1000][1000];
bool cmp(struct NODE a,struct NODE b)
{
    return a.up < b.up;
}
int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> node[i].v;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> node[i].up;
        }
        sort(node+1,node+n+1, cmp);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(j > i)break;
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1] + node[i].v + (j - 1)*node[i].up);
            }
        }
        cout << dp[n][m] << endl;

    }

    return 0;
}
