#include <iostream>
#include <utility>
using namespace std;

pair<int, int> fun()
{
    pair <int, int> a;
    a.first = 1;
    a.second = 2;
    return a;
}
int main()
{
    pair<int, int> p;
    cin >> p.first >> p.second;
    cout << p.first << " " << p.second << endl;
    p = fun();
    cout << p.first << endl;
    return 0;
}
