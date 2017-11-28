#include <iostream>
#include <map>
using namespace std;
map<int,int> mp;
int n,t,ans;
int main()
{
	cin>>n>>t;int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;mp[a]++;
	}
	if(t==0)
	{
		for(auto p:mp)
			if(p.second>1) ans++;
	}
	else
	{
		for(auto p:mp)
			if(mp.find(p.first+t)!=mp.end()) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
