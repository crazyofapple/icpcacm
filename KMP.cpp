#include <iostream>
using namespace std;

void build_next(char *str)
{
    int j = 0, t = next[0]= -1;
    while (j < lent)
    {
        if(t < 0 || str[t] == str[j])
        {
            j++; t++; next[j] = t;
        }
        else t = next[t];
    }
}
void KMP(char *str1,char *str2)
{
    for (i = 0, j = 0; i < len1 && j < len2)
    {
        if(j < 0 && str1[i] == str2[j])
        {
            i++,j++;
        }
        else j = next[j];
    }
}
int main()
{
    string str[100]
    return 0;
}
