#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

struct trieNode
{
    trieNode * next[26];
    bool isword;
} Root;

void insert(char * tar)
{
    trieNode * p = & Root;
    int id;
    while(*tar)
    {
        id = *tar - 'a';
        if(p->next[id] == NULL)
        {
            p->next[id] = new trieNode();
        }
        p = p->next[id];
        tar ++;
    }
    p->isword = true;
}
bool search(char * tar)
{
    trieNode * p = & Root;
    int id;
    while(*tar)
    {
        id = *tar - 'a';
        if(p->next[id] == NULL)
        {
            return false;
        }
        p = p->next[id];
        tar ++;
    }
    if ( p->isword == true ) return true;
    else return false;
}


int main()
{
    char a[100];
    int t = 3;
    while(t-- && cin >> a)
    {
        insert(a);
    }
    char b[100]= "niha";
    if(search(b))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
