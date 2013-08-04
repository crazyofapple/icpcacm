#include<iostream>
using namespace std;
int bin[100005],vis[100005],flag;

int findx(int x){
    if(x!=bin[x])bin[x]=findx(bin[x]);
    return bin[x];
}
void merge(int x, int y)
{
    x = findx(x);
    y = findx(y);
    if(x!=y)bin[x]=y;
    else flag=1;

}
int main()
{
    int n,m,a,b;
    while(cin >> a >> b)
    {
        int co=0;
        flag=0;
        if(a==-1&&b==-1)break;
        if(!a&&!b){cout << "Yes\n";continue;}
        for(int i=1; i<=100005; i++)
        {
            vis[i]=0;
            bin[i]=i;
        }
        while(a||b)
        {
            merge(a,b);
            vis[a]=vis[b]=1;
            cin>>a>>b;
        }
        for(int i=1; i<=100005; i++)
        {
            if(vis[i]&&bin[i]==i&&!flag)co++;
            //cout <<co<< endl;
        }
        if(co==1)cout << "Yes\n"; //<< endl;
        else cout <<"No\n";
    }
    return 0;

}
