#include<iostream>
using namespace std;
int read(int pos)
{
    int ans = 0;
    if (pos > 0)
    {
        ans += tree[pos];
        pos -= pos&-pos;

    }
    return ans;
}
void update(int pos,int val)
{
    while (pos <= MAXN)//MAXN �ܳ���
    {
        tree[pos] += val;
        pos += pos&-pos;
    }
}
//����Ӧ�ã����������еĵ�KС��
int find_Kth(int k,int N)
{
    int now=0;
    for (int i=20; i>=0; i--)
    {
        now|=(1<<i);
        if (now>N || tree[now]>=k) now^=(1<<i);
        else k-=tree[now];
    }
    return now+1;
}
