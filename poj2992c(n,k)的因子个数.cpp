#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 506
using namespace std;

int prime[maxn] = {2,
                   3,
                   5,
                   7,
                   11,
                   13,
                   17,
                   19,
                   23,
                   29,
                   31,
                   37,
                   41,
                   43,
                   47,
                   53,
                   59,
                   61,
                   67,
                   71,
                   73,
                   79,
                   83,
                   89,
                   97,
                   101,
                   103,
                   107,
                   109,
                   113,
                   127,
                   131,
                   137,
                   139,
                   149,
                   151,
                   157,
                   163,
                   167,
                   173,
                   179,
                   181,
                   191,
                   193,
                   197,
                   199,
                   211,
                   223,
                   227,
                   229,
                   233,
                   239,
                   241,
                   251,
                   257,
                   263,
                   269,
                   271,
                   277,
                   281,
                   283,
                   293,
                   307,
                   311,
                   313,
                   317,
                   331,
                   337,
                   347,
                   349,
                   353,
                   359,
                   367,
                   373,
                   379,
                   383,
                   389,
                   397,
                   401,
                   409,
                   419,
                   421,
                   431,
                   433,
                   439,
                   443,
                   449,
                   457,
                   461,
                   463,
                   467,
                   479,
                   487,
                   491,
                   499,
                  };
int n, k;



__int64 fun(int n, int t)
{
    __int64 cnt=0;
    while(n)
    {
        cnt+=n/t;
        n/=t;
    }
    return cnt;
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        __int64 ans = 1;
        for (int i = 0; prime[i] <= n; i++)
        {
            ans *= (1+fun(n, prime[i])) - fun(k, prime[i]) - fun(n-k, prime[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
