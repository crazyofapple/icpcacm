#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

string f, m;
int len;
bool visited[36];

void last(int l, int r)
{
    for (int i = 0; i < len; i++)
    {
        if(!visited[i])
        {
            for (int j = l; j <= r; j++)
            {
                if(m[j] == f[i])
                {
                    visited[i] = true;
                    last(l, j-1);
                    last(j+1, r);
                    cout << f[i];
                    break;
                }
            }
        }
    }
}

int main()
{
    while (cin >> f >> m)
    {
       memset(visited,false,sizeof(visited));
       len = f.length();
       last(0, len - 1);
       cout << endl;
    }
    return 0;
}
