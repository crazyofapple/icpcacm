#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#define maxn 3000006
#define LL long long
using namespace std;

int a, b;
int prime[maxn];
bool isprime[maxn];
int phi[maxn];

void get_phi()
{
    int cnt=0;
    memset(isprime,true,sizeof(isprime));
    for (int i = 2; i < maxn; i++)
    {
        if(isprime[i])
        {
            prime[++cnt]=i;
            phi[i]=i-1;
        }
        for (int j = 1; j <= cnt && i * prime[j] < maxn; j++)
        {
            isprime[ i*prime[j] ] = false;
            if(i % prime[j] == 0)
            {
                phi[ i*prime[j] ] = phi[i] * prime[j];
            }
            else
            {
                phi[ i*prime[j] ] = phi[i] * (prime[j] - 1);
            }
        }
    }
}
int main()
{
    LL ans;
    get_phi();
    while(~scanf("%d%d",&a, &b))
    {
        ans=0;
        for (int i = a; i <= b ;i++)
        {
            ans += phi[i];
        }
        cout << ans << endl;
    }
    return 0;
}
