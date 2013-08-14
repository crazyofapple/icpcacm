#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define LL long long
#define maxn 16000000
using namespace std;

LL mod;
int x, m, k;
LL p[maxn];
bool prime[maxn];
int cnt=1;
struct Matrix
{
    LL ma[2][2];
    Matrix operator*(const Matrix a)
    {
        Matrix ans;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                ans.ma[i][j]=0;
                for (int k = 0; k < 2; k++)
                {
                    ans.ma[i][j]+= ((ma[i][k]*a.ma[k][j])%mod);
                    ans.ma[i][j] %= mod;
                }
            }
        }
        return ans;
    }
};
Matrix a = {1,1,1,0};

void isprime()
{
    memset(prime, true, sizeof(prime));
    for (int i = 2; i <= maxn; i++)
    {
        if(prime[i])
        {
            p[cnt++]=i;
            for (int j = 2*i; j < maxn; j+=i)
            {
                prime[j] = false;
            }
        }
    }
    p[1]=3;p[2]=4;
}

Matrix mul2(LL k)
{
    Matrix ans = a, t = a;
    while(k)
    {
        if(k&1) ans = ans * t;
        k>>=1;
        t = t * t;
    }
    return ans;
}
int main()
{
    isprime();
    int ncase, t;
    Matrix ans;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d%d",&k,&x,&m);
        t = p[k];
        mod = m * x;
        while(1)
        {
            ans = mul2(t);
            if(ans.ma[1][1]%x==0)
            {
                break;
            }
            t++;
        }
        ans = mul2(t);
        cout << ans.ma[1][1]/x <<endl;
    }
    return 0;
}

