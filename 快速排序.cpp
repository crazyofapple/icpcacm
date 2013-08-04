#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int  cmp(const void *a, const void * b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //qsort(a,n,sizeof(int),cmp);
    sort(a,a+n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    delete []a;
    return 0;
}
