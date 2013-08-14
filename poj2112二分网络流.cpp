#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 280
#define edge 90090
#define inf 0x3f3f3f3f
using namespace std;

int first[maxn],dis[maxn],num[maxn];
int vv[edge],ww[edge],nxt[edge];
int dist[maxn][maxn];
int e,NN,k,c,m;
void addEdge(int u,int v,int w)
{
	vv[e] = v;	ww[e] = w;		nxt[e] = first[u];	first[u] = e++;
	vv[e] = u;	ww[e] = 0;		nxt[e] = first[v];		first[v] = e++;
}
int dfs(int u,int s,int d,int cost)
{
	if(u == d)	return cost;
	int ans = 0;
	int _min = NN;
	for(int i = first[u];i != -1;i = nxt[i])
	{
		int v = vv[i];
		if(ww[i])
		{
			if(dis[v] + 1 == dis[u])
			{
				int t = dfs(v,s,d,min(ww[i],cost));
				ww[i] -= t;
				ww[i^1] += t;
				ans += t;
				cost -= t;
				if(dis[s] == NN)		return ans;
				if(!cost)	break;
			}
			if(_min > dis[v])		_min = dis[v];
		}
	}
	if(!ans)
	{
		if(--num[dis[u]] == 0)	dis[s] = NN;
		dis[u] = _min + 1;
		++num[dis[u]];
	}
	return ans;
}
int isap(int s,int d)
{
	memset(dis,0,sizeof(dis));
	memset(num,0,sizeof(num));
	num[0] = NN;
	int ans = 0;
	while(dis[s] < NN)
		ans += dfs(s,s,d,inf);
	return ans;
}
void build(int d)
{
	e = 0 ;	NN = k+c+2;
	memset(first,-1,sizeof(first));
	for(int i = k+1;i <= k+c;i++)
	{
		addEdge(0,i,1);
	}
	for(int i = 1;i <= k;i++)
	{
		addEdge(i,k+c+1,m);
	}
	for(int i = k+1;i <= k+c;i++)
	{
		for(int j = 1;j <= k;j++)
		{
			if(dist[i][j] <= d)
			{
				addEdge(i,j,1);
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&k,&c,&m)==3)// k 是挤奶器  c 是奶牛  m是每台挤奶器最大挤的奶牛数每天
	{
		memset(dist,0x3f,sizeof(dist));
		for(int i = 1;i <=k+c;i++)
		{
			for(int j = 1;j <=k+c;j++)
			{
				int v;	scanf("%d",&v);
				if(v == 0 && i != j)	continue;
				else dist[i][j] = v;
			}
		}
		for(int i = 1;i <= k+c;i++)
		{
			for(int j = 1;j <= k+c;j++)
			{
				for(int o = 1;o <= k+c;o++)
				{
					dist[j][o] = min(dist[j][o],dist[j][i] + dist[i][o]);
				}
			}
		}
		int l = 0,r = 0;
		for(int i = 1;i <= k+c;i++)
		{
			for(int j = 1;j <= k+c;j++)
			{
				r = max(r,dist[i][j]);
			}
		}
		while(l < r)
		{
			int mid = (l + r)>>1;
			build(mid);
			int temp = isap(0,k+c+1);
			if(temp >= c)	r = mid;
			else l = mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}

