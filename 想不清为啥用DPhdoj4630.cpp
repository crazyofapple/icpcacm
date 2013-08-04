#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define maxn 1006
using namespace std;
int a[maxn], n;
int dp[maxn][maxn];
void work()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i)
    {
        dp[i][i] = 0;
        for (int j = i + 1; j < n; ++j)
        {
            dp[i][j] = max(max(dp[i + 1][j], dp[i][j - 1]), __gcd(a[i], a[j]));
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << dp[l][r] << endl;
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        work();
    return 0;
}
