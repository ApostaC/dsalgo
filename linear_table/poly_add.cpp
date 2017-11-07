#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int co,ex,flag=0;
		map<int,int> poly;
		poly.clear();
		while(cin>>co>>ex)
		{
			if(ex<0)
			{
				flag++;
				if(flag>=2) break;
				continue;
			}
			if(poly.find(ex)!=poly.end()) poly[ex]+=co;
			else poly[ex]=co;
		}
		for(auto it=poly.rbegin();it!=poly.rend();it++)
		{
			if(it->second==0) continue;
			printf("[ %d %d ] ",it->second,it->first);
		}
		cout<<endl;
	}
	return 0;
}

