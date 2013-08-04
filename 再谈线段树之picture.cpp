#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int ym[10200];//注意区间要开大点 不然RE

struct Tree
{
    int li,ri,lb,rb;//li,ri左右端点的值
    int lenth,ans,cover;//lenth表示被覆盖至少一次的长度
    //ans记录子区间个数,lb,rb记录左右端点被覆盖次数
    //cover记录整个区间被覆盖的次数
} s[50000];

struct node
{
    int x,y1,y2;
    int flag;
} t[50000]; //表示左，右边的节点

int cmp1(int x,int y)
{
    return x<y;
}

int cmp2(struct node st,struct node sd)
{
    if(st.x!=sd.x)
        return st.x<sd.x;
    else
        return st.flag>sd.flag;
    //这里要非常注意，因为要计算并周长，
    //当两个边x一样的时候，要将左边先插入！
}

int len(int num)
{
    if(s[num].cover>0)
        s[num].lenth=s[num].ri-s[num].li;
    else
        s[num].lenth=s[num+num].lenth+s[num+num+1].lenth;
}

int slen(int num)
{
    if(s[num].cover>0)
        s[num].ans=1;
    else
    {
        s[num].ans=s[num+num].ans+s[num+num+1].ans;
        if(s[num+num].rb!=0&&s[num+num+1].lb!=0)
            s[num].ans--;
        //左子树的右端点如果跟右子树的左端点都被覆盖了
        //说明在整个区间里，有一个区间横跨左右子树，
        //但被重复计算了，所以要减去1！
    }
}

int Build(int x,int y,int num)
{
    s[num].li=ym[x];
    s[num].ri=ym[y];
    s[num].lenth=0;
    s[num].cover=s[num].rb=s[num].lb=s[num].ans=0;
    if(x+1==y)
        return 0;
    int mid=(x+y)>>1;
    Build(x,mid,num+num);
    Build(mid,y,num+num+1);
}

int modify(int num,struct node st)
{
    if(st.y1==s[num].li)    s[num].lb+=st.flag;
    if(st.y2==s[num].ri)    s[num].rb+=st.flag;
    if(st.y1==s[num].li&&st.y2==s[num].ri)
    {
        s[num].cover+=st.flag;
    }
    else
    {
        if(st.y1>=s[num+num].ri)
            modify(num+num+1,st);
        else if(st.y2<=s[num+num+1].li)
            modify(num+num,st);
        else
        {
            struct node sd=st;
            sd.y2=s[num+num].ri;
            modify(num+num,sd);
            sd=st;
            sd.y1=s[num+num+1].li;
            modify(num+num+1,sd);
        }
    }
    len(num);
    slen(num);
}

int main()
{
    int cas,i,j;
    int x1,x2,y1,y2;
    int sum=0;
    while(scanf("%d",&cas)!=EOF)
    {
        sum=0;
        for(j=1,i=1; i<=cas; i++,j+=2)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            ym[j]=y1;
            t[j].x=x1;
            t[j].y1=y1;
            t[j].y2=y2;
            t[j].flag=1;
            ym[j+1]=y2;
            t[j+1].x=x2;
            t[j+1].y1=y1;
            t[j+1].y2=y2;
            t[j+1].flag=-1;

        }
        sort(ym+1,ym+j,cmp1);
        sort(t+1,t+j,cmp2);
        Build(1,j-1,1);
        int lastn=0,lasts=0;
        //lasts 表示上次Y上次的投影长度，lastn
        //表示Y上次的投影连续区间的个数
        //其实连续区间就是指图形从上到下有多少个不相连的部分
        //因为求周长，所以有多少个部分就要把X的区间长度
        //乘以这个区间个数，因为他们每个部分的上下边不重叠
        for(i=1; i<j; i++)
        {
            modify(1,t[i]);
            sum+=abs(lasts-s[1].lenth);
            if(i!=1)
            {
                sum+=lastn*(t[i].x-t[i-1].x)*2;
            }
            lastn=s[1].ans;
            //当初我答案一直错，检查了很久，最后终于发现是
            //把lastn=s[1].ans；放在了if语句里面，这样的话影响了第2次的计算。所以周长计算出来会有点偏小，因为我第二次的lastn还是=0，应该是等于1，呵呵
            lasts=s[1].lenth;

        }
        printf("%d\n",sum);
    }
}
