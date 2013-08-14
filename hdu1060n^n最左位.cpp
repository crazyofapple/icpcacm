#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
double t;

int main()
{
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d",&n);
        t = n * log10((double)n);
        t = pow(10.0 ,(t - floor(t)) * 1.0);
        printf("%d\n", (int)t);
    }
	return 0;
}
