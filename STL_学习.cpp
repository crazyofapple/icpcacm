//vector(����������������)��list(�б�����������)��deque(˫�����)��set(����)��
//map(ӳ��)��stack(ջ)��queue(����)��priority_queue(���ȶ���)�ȣ�
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <deque>
#include <set>
#include <iostream>
//#include <vetctor>
using namespace std;
int main(){
    vector<int> L;
    int x,t;
    cin >> t;
    while (t--) {cin >> x; L.push_back(x);}
    for (int i=L.size()-1; i>=0; i--) cout << L[i] << " ";
    cout << endl;
    return 0;
}
