#include<stdio.h>
#include<string.h>
#define N 50005
struct node
{
	int x,y;
	int max;//花的个数
	int max0;//空瓶子的个数
	int flag;
}a[N*3];
void CreatTree(int t,int x,int y)
{
	a[t].x=x;
	a[t].y=y;
	a[t].max=0;
	a[t].max0=y-x+1;
	a[t].flag=-1;
	if(x==y)
		return ;
	int temp=t*2;
	int mid=(x+y)/2;
	CreatTree(temp,x,mid);
	CreatTree(temp+1,mid+1,y);
	return ;
}
void ChangeTree(int t,int x)
{
	if(x==1)
	{
		a[t].max=a[t].y-a[t].x+1;
		a[t].max0=0;
		a[t].flag=1;
	}
	else
	{
		a[t].max0=a[t].y-a[t].x+1;
		a[t].max=0;
		a[t].flag=0;
	}
	return ;
}
int FindTree(int t,int x,int y)
{
	if(a[t].x==x&&a[t].y==y)
		return a[t].max0;
	int temp=t*2;
	int mid=(a[t].x+a[t].y)/2;
	if(a[t].flag!=-1)
	{
		ChangeTree(temp,a[t].flag);
		ChangeTree(temp+1,a[t].flag);
		a[t].flag=-1;
	}
	if(y<=mid)
		return FindTree(temp,x,y);
	else if(x>mid)
		return FindTree(temp+1,x,y);
	else
		return FindTree(temp,x,mid)+FindTree(temp+1,mid+1,y);
}
int findTree(int t,int x,int y)
{
	if(a[t].x==x&&a[t].y==y)
		return a[t].max;
	int temp=t*2;
	int mid=(a[t].x+a[t].y)/2;
	if(a[t].flag!=-1)
	{
		ChangeTree(temp,a[t].flag);
		ChangeTree(temp+1,a[t].flag);
		a[t].flag=-1;
	}
	if(y<=mid)
		return findTree(temp,x,y);
	else if(x>mid)
		return findTree(temp+1,x,y);
	else
		return findTree(temp,x,mid)+findTree(temp+1,mid+1,y);
}
void DeleteTree(int t,int x,int y)
{
	if(a[t].x==x&&a[t].y==y)
	{
		ChangeTree(t,0);
		a[t].flag=0;
		return ;
	}
	int temp=t*2;
	int mid=(a[t].x+a[t].y)/2;
	if(a[t].flag!=-1)
	{
		ChangeTree(temp,a[t].flag);
		ChangeTree(temp+1,a[t].flag);
		a[t].flag=-1;
	}
	if(y<=mid)
		DeleteTree(temp,x,y);
	else if(x>mid)
		DeleteTree(temp+1,x,y);
	else
	{
		DeleteTree(temp,x,mid);
		DeleteTree(temp+1,mid+1,y);
	}
	a[t].max=a[temp].max+a[temp+1].max;
	a[t].max0=a[temp].max0+a[temp+1].max0;
	return ;
}
int InsertTree(int t,int y)
{
	int ans;
	if(a[t].x==a[t].y)
		return a[t].x;
	int temp=t*2;
	int mid=(a[t].x+a[t].y)/2;
	if(a[t].flag!=-1)
	{
		ChangeTree(temp,a[t].flag);
		ChangeTree(temp+1,a[t].flag);
		a[t].flag=-1;
	}
	if(y>a[temp].max0)
		ans=InsertTree(temp+1,y-a[temp].max0);
	else
		ans=InsertTree(temp,y);
	a[t].max=a[temp].max+a[temp+1].max;
	a[t].max0=a[temp].max0+a[temp+1].max0;
	return ans;
}
void UpdateTree(int t,int x,int y)
{
	if(a[t].x==x&&a[t].y==y)
	{
		ChangeTree(t,1);
		a[t].flag=1;
		return ;
	}
	int temp=t*2;
	int mid=(a[t].x+a[t].y)/2;
	if(a[t].flag!=-1)
	{
		ChangeTree(temp,a[t].flag);
		ChangeTree(temp+1,a[t].flag);
		a[t].flag=-1;
	}
	if(y<=mid)
		UpdateTree(temp,x,y);
	else if(x>mid)
		UpdateTree(temp+1,x,y);
	else
	{
		UpdateTree(temp,x,mid);
		UpdateTree(temp+1,mid+1,y);
	}
	a[t].max=a[temp].max+a[temp+1].max;
	a[t].max0=a[temp].max0+a[temp+1].max0;
	return ;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		CreatTree(1,0,n-1);
		while(m--)
		{
			int t,x,y;
			scanf("%d%d%d",&t,&x,&y);
			if(t==1)
			{
				int temp;
				temp=FindTree(1,x,n-1);
				if(temp==0)
					printf("Can not put any one.\n");
				else if(temp<y)
				{
					int k;
					if(x>=1)
						temp=FindTree(1,0,x-1);
					else
						temp=0;
					k=1+temp;
					k=InsertTree(1,k);
					temp=InsertTree(1,a[1].max0);
					UpdateTree(1,x,n-1);
					printf("%d %d\n",k,temp);
				}
				else
				{
					int k;
					if(x>=1)
						temp=FindTree(1,0,x-1);
					else
						temp=0;
					k=1+temp;
					temp+=y;
					k=InsertTree(1,k);
					temp=InsertTree(1,temp);
					UpdateTree(1,x,temp);
					printf("%d %d\n",k,temp);
				}
			}
			else if(t==2)
			{
				int temp;
				temp=findTree(1,x,y);
				DeleteTree(1,x,y);
				printf("%d\n",temp);
			}
		}
		printf("\n");
	}
	return 0;
}
