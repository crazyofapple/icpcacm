#include <iostream>
#include <cstdio>
using namespace std;
int foo(int n, int k)
{
    int r = 0;
    for (int i = 2; i <= n; i++)
    {
        r = (r+k)%i;
    }
    return r+1;
}
int main()
{
    int k,n;
    while(cin >> n >> k)
    {
        cout << foo(n,k) << endl;
    }
}
