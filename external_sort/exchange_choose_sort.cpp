#include <iostream>
#include <algorithm>
#define MAXN 100010
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define heap(a,b) heap(a,b,cmp)
using namespace std;
int m,n,a[MAXN],h[MAXN];
bool cmp(int a,int b){return a>b;}
int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>h[i];
	int heap_size=n;
	int len=m<heap_size-1?m:heap_size;
	if(!std::is_heap(h,h+n,cmp)) std::make_heap(h,h+n,cmp);
	for(int i=0;i<len;i++)
	{
		cout<<h[0]<<" ";
		if(a[i]>=h[0]) h[0]=a[i];
		else
		{
			h[0]=h[heap_size-1];
			h[heap_size-1]=a[i];
			heap_size--;
		}
		std::make_heap(h,h+heap_size,cmp);
	}
}

