#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 12
int tree[100];
//求 sum[1,pos]的答案
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
//把a[pos]加上val
void update(int pos,int val)
{
		while (pos<=MAXN) //MAXN为总长度
		{
			tree[pos]+=val;
			pos+=pos&-pos;
		}
}
//特殊应用：找整个数列的第K小数
//int find_Kth(int k,int N)
//{
//	int now=0;
//	for (int i=20;i>=0;i--)
//	{
//		now|=(1<<i);
//		if (now>N || tree[now]>=k) 			now^=(1<<i);
//		else k-=tree[now];
//	}
//	return now+1;
//}

int main()
{
    //cout << read(3) <<endl;

    //update(9,18);
    for (int i = 1; i <= 12; i++) update(i,i);
    cout << read(10) << endl;
    return 0;
}
