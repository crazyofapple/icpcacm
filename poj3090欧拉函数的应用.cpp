#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

__int64 n, sum;

__int64 euler(__int64 n)
{
    __int64 res=n,a=n;
    for(__int64 i=2; i*i<=a; i++)
    {
        if(a%i==0)
        {
            res=res/i*(i-1);
            while(a%i==0) a/=i;
        }
    }
    if(a>1) res=res/a*(a-1);
    return res;
}
int main()
{
    __int64 ncase;
    cin >> ncase;
    __int64 cas=1;
    while(ncase--)
    {
        cin >> n;
        sum=0;
        for(__int64 i = 2; i <= n; i++)
        {
            sum += euler(i);
        }
        printf("%lld %lld %lld\n",cas++, n, sum*2+3);
    }

    return 0;

}
