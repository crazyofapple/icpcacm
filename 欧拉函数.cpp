
//ֱ�����ŷ������
long long euler(int n)  //����euler(n)
{
    long long res=n,a=n;
    for(long long i=2; i*i<=a; i++)
    {
        if(a%i==0)
        {
            res=res/i*(i-1);//�Ƚ��г�����Ϊ�˷�ֹ�м����ݵ����
            while(a%i==0) a/=i;
        }
    }
    if(a>1) res=res/a*(a-1);
    return res;
}
