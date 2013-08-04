#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int vis[1000],prime[1000],can[1000]={1},n;

int isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
void dfs(int cur)
{
    if(cur==n && prime[can[n-1]+can[0]])
    {
        for (int i = 0; i < n ; i++) cout << can[i] << " ";
        cout << endl;
    }
    for (int j = 2; j <= n; j++)
    {
        if(prime[j+can[cur-1]] && vis[j] == 0)
        {
            can[cur] = j;
            vis[j] = 1;
            dfs(cur+1);
            vis[j] = 0;
        }
    }
}
int main()
{
    int k = 1;
    while(scanf("%d",&n)!=EOF)
    {
        printf("Case %d:\n",k++);
        for(int i = 3; i <= n*2; i++)
        {
            if(isprime(i)) prime[i] = 1;
        }
        dfs(1);
        cout  <<endl;
    }
    return 0;
}
