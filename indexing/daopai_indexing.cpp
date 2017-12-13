#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MAXN 1010
using namespace std;
typedef set<string> Set;
Set books[MAXN];
int n,m;
int main()
{
	cin>>n;
	int t;string s;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		for(int j=0;j<t;j++) 
		{
			cin>>s;
			books[i].insert(s);
		}
	}
	cin>>m;
	bool flag;
	for(int i=0;i<m;i++)
	{
		cin>>s;flag=false;
		for(int i=1;i<=n;i++)
		{	if(books[i].count(s)) {cout<<i<<" ";flag=true;}}
		if(!flag) cout<<"NOT FOUND";
		cout<<endl;
	}
}
