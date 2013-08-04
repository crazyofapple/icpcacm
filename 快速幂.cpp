int fun(int a, int b)
{
    int ans = 1;
    int t = a;
    while(b)
    {
        if(b&1)ans*=t;
        t*=t;
        b>>=1
    }
    return ans;
}
