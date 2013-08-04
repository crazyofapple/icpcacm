#include<iostream>
using namespace std;
int main()
{
    int c2[100],i,j,k,n,c1[100];
    while (cin >> n)
    {
        for (i = 0; i <= n; i++)
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        for (i = 2; i <= 17; i++)
        {
            for (j = 0; j <= n; j++)
            {
                for (k = 0; k+j <= n; k += i * i)
                {
                    c2[j + k] += c1[j];
                }
            }
            for (j = 0; j <= n; j++)
            {
                c1[j] = c2[j];c2[j] = 0;
            }

        }
        cout << c1[n] << endl;
    }
    return 0;
}
