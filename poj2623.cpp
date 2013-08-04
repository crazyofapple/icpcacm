#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int n;
unsigned int t,t2;
priority_queue<unsigned int, vector<unsigned int>, greater<unsigned int> > q;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        q.push(t);
        if(q.size() > (n/2+1)) q.pop();
    }
    if(n%2)
    {
        printf("%.1lf\n", (double)q.top());
    }
    else
    {
        t = q.top();
        q.pop();
        t2 = q.top();
        printf("%.1lf\n", (double)(t+t2)/2.0);
    }
}
