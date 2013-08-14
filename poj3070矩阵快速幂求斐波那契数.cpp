#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define MOD 1
using namespace std;

struct M
{
    __int64 m[2][2];
};

M a = {1,1,1,0};

M mul(const M a, const M b)
{
    M tmp;
    for (long long i = 0; i < 2; i++)
    {
        for (long long j = 0; j < 2; j++)
        {
            tmp.m[i][j]=0;
            for (long long k = 0; k < 2; k++)
            {
                tmp.m[i][j] += (a.m[i][k]*b.m[k][j]);
                //tmp.m[i][j] %= MOD;
            }
        }
    }
    return tmp;
}

M mul2(__int64 n)
{
    M ans = a, t = a;
    while(n)
    {
        if(n&1) ans=mul(ans,t);
        t=mul(t,t);
        n>>=1;
    }
    return ans;
}
int main()
{
    __int64 n;
    M tmp;
    while(cin >> n)
    {
        if(n==-1)break;
        tmp = mul2(n);
        printf("%d\n",tmp.m[1][1]);
    }
}
