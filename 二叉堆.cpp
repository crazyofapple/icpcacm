//int top()
//{
//	return a[1];
//}
//void insert(int x)
//{
//	a[++N]=x;
//	swim(N);
//}
//void pop()
//{
//	a[1]=a[N];
//	N--;
//	sink(1);
//}
//void swim(int id)
//{
//	while(id!=1)
//	{
//		if(a[id/2]<a[id])
//		{
//			swap(a[id/2],a[id]);
//			id/=2;
//		}
//		else break;
//	}
//}
//void sink(int id)
//{
//	while(id*2<=N)
//	{
//		int ma=a[id],pos=id;
//		if(a[id*2]>ma)
//		{
//			ma=a[id*2],pos=2*id;
//		}
//		if(id*2+1<=N&&a[id*2+1]>ma)
//		{
//			ma=a[id*2+1],pos=2*id+1;
//		}
//		if(id==pos)break;
//		swap(a[id],a[pos]);id=pos;
//	}
//}
// range heap example
#include <iostream>     // cout
#include <algorithm>    // make_heap, pop_heap, push_heap, sort_heap
#include <vector>       // vector
using namespace std;

int main () {
  int myints[] = {10,20,30,5,15};
  vector<int> v(myints,myints+5);

  make_heap (v.begin(),v.end());
  cout << "initial max heap   : " << v.front() << '\n';

  pop_heap (v.begin(),v.end()); v.pop_back();
  cout << "max heap after pop : " << v.front() << '\n';

  v.push_back(99); push_heap (v.begin(),v.end());
  cout << "max heap after push: " << v.front() << '\n';

  sort_heap (v.begin(),v.end());

  cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    cout << ' ' << v[i];

  cout << '\n';

  return 0;
}
