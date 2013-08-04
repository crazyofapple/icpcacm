#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define maxn 1006
using namespace std;

int a[1006];
int cot(int n)
{
    for (int i = 2; n != 1; i++)
    {
        if(n%i==0)
        {
            while(n%i==0&&n!=1)
            {
                a[i]++;
                n/=i;
            }
        }
    }
    int ans=1;
    for (int i = 0; i <1000; i++)
    {
        if(a[i])
            ans*=(a[i]+1);
    }
    return ans;
}
int main()
{
    int num;
    cin >> num;
    cout << cot(num) << endl;
    return 0;
}
