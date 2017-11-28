#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 100010
using namespace std;
int a[MAXN];
long long ans;
void merge(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	merge(l,mid);
	merge(mid+1,r);
	int * temp = new int[r-l+1];
	int ll=l,rr=mid+1,tt=0;
	while(ll<=mid && rr<=r)
	{
		if(a[ll]<=a[rr])
		{
			temp[tt++]=a[ll++];
		}
		else
		{
			temp[tt++]=a[rr++];ans+=(rr-tt-l);
		}
	}
	while(ll<=mid){ temp[tt++]=a[ll++];}
	while(rr<=r) temp[tt++]=a[rr++];
	memcpy((void*)&a[l],(const void *)temp,sizeof(int)*(r-l+1));
	delete[] temp;
//	cout<<"after merging ("<<l<<","<<r<<") ans= "<<ans<<endl;
}
int n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[n-i-1];
	merge(0,n-1);
	cout<<ans;
	return 0;
}
