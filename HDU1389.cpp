#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int vis[100],n,i,j,ans;
struct Node
{
    int score, time;
}node[100];
int cmp(struct Node a, struct Node b)
{
    if (a.score != b.score)
    {
        return a.score > b.score;
    }
    else
        return a.time < b.time;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(vis,0,sizeof(vis));
        cin >> n;
        ans = 0;

        for (i = 0; i < n; i++)
        {
            cin >> node[i].time;
        }
        for (i = 0; i < n; i++)
        {
            cin >> node[i].score;
        }
        sort(node,node+n,cmp);
        for (i = 0; i < n; i++)
        {
            j = node[i].time;
            while(j)
            {
                if(vis[j] == 0)
                   {
                       vis[j] = 1;break;
                   }
                else j--;
            }
            if (j == 0)
                ans += node[i].score;
        }
        cout << ans  <<endl;
    }
    return 0;

}
