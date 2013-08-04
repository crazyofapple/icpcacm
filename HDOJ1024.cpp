#include<iostream>
#include<cstring>
using namespace std;
int dp[1000],num[1000],t[1000];
int main()
{
    int m, n, sum, j;
    while (cin >> m >> n)
    {
        memset(dp, 0, sizeof(dp));
        memset(num, 0 ,sizeof(num));
        for ( int i = 1; i <= n; i++)
        {
            cin >> num[i];
        }
        for (int i = 1; i <= m; i++)
        {
            sum = -22222;
            for (j = i; j <= n; j++)
            {
                dp[j] =  max(dp[j-1],t[j-1]) + num[j];
                t[j - 1] = sum;
                sum = max(sum, dp[j]);
            }
            t[j - 1] = sum;
        }
        cout << sum << endl;
    }
    return 0;
}
