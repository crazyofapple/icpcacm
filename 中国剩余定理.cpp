#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//intChina(int r)
//{
//    M = -1;
//    int i,MI
//}
//int main()
//{
//    int ncase = 0, p, e, i, d, temp;
//    while(scanf("%d%d%d%d",&p,&e,&i,&d)!=EOF)
//    {
//        if(p == -1 && e ==-1 && i == -1 && d==-1) break;
//        ncase++;
//        a[1] = p; a[2] = e; a[3] = i;
//        m[1] = 23; m[2] = 28; m[3] = 33;
//
//    }
//    return 0;
//}
/*===================================================*/
/*	求x, y使得gcd(a, b) = a * x + b * y; */
int extgcd(int a, int b, int &x, int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int d = extgcd(b,a%b,x,y);
    int t = x;
    x= y;
    y = t-a/b*y;
    return d;

}
// 模线性方程 a * x = b (% n)
//void modeq(int a,	int b,	int n)  	// ! n > 0
//{
//    int e, i, d, x, y;
//    d = extgcd(a, n, x, y);
//    if (b % d > 0) printf("No answer!\n");
//    else
//    {
//        e = (x * (b / d)) % n;
//        for (i = 0; i < d; i++)	// !!! here x maybe < 0
//            printf("%d-th ans: %d\n", i+1, (e+i*(n/d))%n);
//    }
//}
int china(int b[],	int w[],	int k)
{
    int i, d, x, y, m, a = 0, n = 1;
    for (i = 0; i < k; i++) n *= w[i];   // !	注意不能overflow
    for (i = 0; i < k; i++)
    {
        m = n / w[i];
        d = extgcd(w[i], m, x, y);
        a = (a + y * m * b[i]) % n;
    }
    if (a > 0) return a;
    else return (a + n);
}

int main()
{
    int b[100],w[100],n;
    while(cin >> n)
    {
        for (int i = 0; i < n; i++) cin >> w[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        cout << china(b,w,n) << endl;
    }
    return 0;
}
