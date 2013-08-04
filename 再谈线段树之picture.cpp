#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int ym[10200];//ע������Ҫ����� ��ȻRE

struct Tree
{
    int li,ri,lb,rb;//li,ri���Ҷ˵��ֵ
    int lenth,ans,cover;//lenth��ʾ����������һ�εĳ���
    //ans��¼���������,lb,rb��¼���Ҷ˵㱻���Ǵ���
    //cover��¼�������䱻���ǵĴ���
} s[50000];

struct node
{
    int x,y1,y2;
    int flag;
} t[50000]; //��ʾ���ұߵĽڵ�

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
    //����Ҫ�ǳ�ע�⣬��ΪҪ���㲢�ܳ���
    //��������xһ����ʱ��Ҫ������Ȳ��룡
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
        //���������Ҷ˵����������������˵㶼��������
        //˵���������������һ������������������
        //�����ظ������ˣ�����Ҫ��ȥ1��
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
        //lasts ��ʾ�ϴ�Y�ϴε�ͶӰ���ȣ�lastn
        //��ʾY�ϴε�ͶӰ��������ĸ���
        //��ʵ�����������ָͼ�δ��ϵ����ж��ٸ��������Ĳ���
        //��Ϊ���ܳ��������ж��ٸ����־�Ҫ��X�����䳤��
        //������������������Ϊ����ÿ�����ֵ����±߲��ص�
        for(i=1; i<j; i++)
        {
            modify(1,t[i]);
            sum+=abs(lasts-s[1].lenth);
            if(i!=1)
            {
                sum+=lastn*(t[i].x-t[i-1].x)*2;
            }
            lastn=s[1].ans;
            //�����Ҵ�һֱ������˺ܾã�������ڷ�����
            //��lastn=s[1].ans��������if������棬�����Ļ�Ӱ���˵�2�εļ��㡣�����ܳ�����������е�ƫС����Ϊ�ҵڶ��ε�lastn����=0��Ӧ���ǵ���1���Ǻ�
            lasts=s[1].lenth;

        }
        printf("%d\n",sum);
    }
}
