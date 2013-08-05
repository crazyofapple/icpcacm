#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int n;
int tree[50006];
int read(int pos)
{
		int ans=0;
		while (pos>0)
		{
			ans+=tree[pos];
			pos-=pos&-pos;
		}
		return ans;
}
void update(int pos,int val)
{
		int ans=0;
		while (pos<=n) //n为总长度
		{
			tree[pos]+=val;
			pos+=pos&-pos;
		}
}
int main()
{
    int ncase, cas=0;
    //freopen("in.in","r",stdin);
    cin >> ncase;
    int a,x,y;string str;

    while(ncase--)
    {
        scanf("%d",&n);
        printf("Case %d:\n",++cas);
        memset(tree,0,sizeof(tree));
        for (int i = 1; i <= n; i++) {scanf("%d",&a);update(i,a);}
        while(cin >> str && str != "End")
        {
            scanf("%d%d",&x,&y);
            if(str[0] == 'A')
            {
                update(x, y);
            }
            else if(str[0] == 'Q')
            {
                printf("%d\n",read(y)-read(x-1));
            }
            else if(str[0] == 'S')
            {
                update(x, -y);
            }
        }
    }
    return 0;
}
