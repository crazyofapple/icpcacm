#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;

int n,a[50006];

int ans,sum,num;
int solve()
{
    int m = 1;
    for (int i = 1;i <= n; i++)
    {
        for (int j = m; j <= n; j++)
        {
            if(a[j-1] <= a[j+1])
            {
                int t = a[j] + a[j-1];
                sum += t;
                num--;
                if(num==1) return sum;
                int t1 = j - 2, flag = 0;
                while(t1 >= m-1)
                {
                    if(!flag && a[t1] > t)
                    {
                        a[t1+2] = t;
                        a[t1+1] = a[t1];
                        flag = 1;
                    }
                    else
                    {
                        if(!flag)
                        {
                            a[t1+2] = a[t1];
                        }
                        else a[t1+1] = a[t1];
                    }
                    t1--;
                    cout << a[t1+1] << " $$" ;
                }
                m = n-num+1;
                break;
            }
        }
    }
}
int main()
{
    while(cin >> n,n)
    {
        sum = 0; num = n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        a[0] = a[n+1] = inf;
        cout << solve() << endl;
    }
    return 0;
}
