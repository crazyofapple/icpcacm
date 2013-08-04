#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define maxn 35006
using namespace std;

int prime[maxn];
bool notprime[maxn];

void get_prime()
{
    int cnt=-1;
    for (int i = 2; i < maxn; i++)
    {
        if(!notprime[i])
        {
            prime[++cnt]=i;
            for (int j = 2*i; j < maxn; j+=i)
            {
                notprime[j]=true;
            }
        }
    }

}
void exgcd(int a,int b,int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return ;
    }
    exgcd(b,a%b,x,y);
    int t = x;
    x = y;
    y = t - a/b*y;
}
int main()
{
    int ncase,_i,_j,n,p,q,x1,x2;
    cin >> ncase;
    get_prime();
    while(ncase--)
    {
        cin >> n;
        int cnt2=0;
        while(1)
        {
            if(n%prime[cnt2]==0)
            {
                p = prime[cnt2];
                q = n/prime[cnt2];
                break;
            }
            cnt2++;
        }
        exgcd(p,q,_i,_j);
        x1 = _i<0 ? (p*_i + p*q) : (p*_i);
        exgcd(q,p,_i,_j);
        x2 = _i<0 ? (q*_i + p*q) : (q*_i);
        if(x1 > x2) swap(x1,x2);
        printf("0 1 %d %d\n", x1,x2);
    }
    return 0;
}
