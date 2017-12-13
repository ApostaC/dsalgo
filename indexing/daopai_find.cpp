#include <iostream>
#include <vector>
#include <bitset>
#include <map>
using namespace std;

map<int,int> mp;
typedef bitset<1010> Bitset;
class Table
{
	public:
		vector<int> data;
		Bitset bst;
		void toBitSet()
		{
			for(auto d : data)
				bst.set(mp[d],true);
			return;
		}		
};
Table tables[110];
int n,m;
int revmap[1010];
int main()
{
	cin>>n;int ci,a;
	for(int i=0;i<n;i++)
	{
		cin>>ci;
		for(int j=0;j<ci;j++)
		{
			cin>>a;
			tables[i].data.push_back(a);
			mp[a]++;
		}
	}
	int cnt=0;
	for(auto & m:mp)
	{
		m.second=cnt;
		revmap[cnt]=m.first;
		cnt++;
	}
	/*for(auto m:mp)
		cout<<"("<<m.first<<","<<m.second<<")"<<endl;
	for(int i=0;i<cnt;i++)cout<<revmap[i]<<" ";
	cout<<endl;*/
	for(int i=0;i<n;i++) tables[i].toBitSet();
	//for(int i=0;i<n;i++) cout<<tables[i].bst<<endl;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		Bitset bt=0;
		bt=(~bt);
		for(int j=0;j<n;j++)
		{
			cin>>a;
			if(a==1) bt&=tables[j].bst;
			else if(a==-1) bt&=(~tables[j].bst);
			//cout<<j<<" : "<<bt<<endl;
		}
		bool flag=false;
		for(int j=0;j<cnt;j++)
		{
			if(bt[j]){ cout<<revmap[j]<<" ";flag=true;}
		}
		if(!flag) cout<<"NOT FOUND";
		cout<<endl;
	}
	
}
