/*
 分析的思路在http://www.cppblog.com/coreBugZJ/archive/2012/06/04/177481.html

*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a, b,temp,t;
    while (cin >> a >> b)
    {
        if (a > b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        t = floor( ( b - a ) * ( sqrt(5.0) + 1 ) / 2 );
        if ( t == a)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}
