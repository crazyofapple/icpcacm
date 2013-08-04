#include<iostream>
using namespace std;
int f[4];
int foo(int n)
{
    f[1] = 0;
    f[2] = 1;
    for (int i = 0; i < n; i++)
    {
        f[0] = f[1];
        f[1] = f[2];
        f[2] = f[0] + f[1];
    }
    return f[2];
}
int main()
{
    int n;
    while(cin >> n)
    {cout << foo(n) <<endl;}
    return 0;
}
