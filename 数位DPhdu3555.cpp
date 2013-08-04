#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
__int64 n;
__int64 dp[20][3];

void fuck()
{
    dp[0][0] = 1;
    for (int i = 1; i < 21; i++)
    {
        dp[i][0] = dp[i-1][0]*10 - dp[i-1][1];//not 49
        dp[i][1] = dp[i-1][0]; //9
        dp[i][2] = dp[i-1][2]*10 + dp[i-1][1]; //49
    }
}
__int64 shit()
{
    __int64 ans = 0,s[21]; bool flag = false;
    int t = 0;
    while (n)
    {
        s[++t] = n%10;
        n/=10;
    }
    for (int i = t; i >= 1; i--)
    {
        ans += dp[i-1][2] * s[i];
        if (flag)
        {
            ans += dp[i-1][0] * s[i];
        }
        else
        {
            if(s[i] > 4) ans+=dp[i-1][1];
        }
        if(s[i+1] == 4 && s[i] == 9) flag = true;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    fuck();
    while(t--)
    {
        cin >> n;
        n++;
        cout << shit() << endl;
    }
    return 0;
}

