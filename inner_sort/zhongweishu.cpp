#include <iostream>
#include <algorithm>
using namespace std;
int a[10010],n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	std::sort(a,a+n);
	cout<<a[n/2]<<endl;
	return 0;
}
