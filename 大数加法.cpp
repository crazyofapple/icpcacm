#include<iostream>
#include<string>
using namespace std;
int main()
{
    string sum(string s1,string s2);
	string s1,s2;
	cin>>s1>>s2;
    cout<<sum(s1,s2)<<endl;
	return 0;
}
string sum(string s1,string s2)
{
     if(s1.length()<s2.length())
     {
          string temp=s1;
          s1=s2;
          s2=temp;
     }
     for(int i=s1.length()-1,j=s2.length ()-1;i>=0;i--,j--)
     {
          s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));
          if(s1[i]-'0'>=10)
          {
              s1[i]=char((s1[i]-'0')%10+'0');
              if(i)
                   s1[i-1]++;
              else
                   s1='1'+s1;
          }
     }
     return s1;
}
