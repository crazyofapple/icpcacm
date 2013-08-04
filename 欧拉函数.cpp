
//直接求解欧拉函数
long long euler(int n)  //返回euler(n)
{
    long long res=n,a=n;
    for(long long i=2; i*i<=a; i++)
    {
        if(a%i==0)
        {
            res=res/i*(i-1);//先进行除法是为了防止中间数据的溢出
            while(a%i==0) a/=i;
        }
    }
    if(a>1) res=res/a*(a-1);
    return res;
}
