//vector(向量，类似于数组)、list(列表，类似于链表)、deque(双向队列)、set(集合)、
//map(映象)、stack(栈)、queue(队列)、priority_queue(优先队列)等，
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
