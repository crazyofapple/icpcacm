#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace st
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
    cout << binary_search(a,a+n,9) << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    delete []a;
    return 0;
}
