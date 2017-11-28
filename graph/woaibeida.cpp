#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#define MAXN 35
#define MAXI (1<<28)
using namespace std;

map<string,int> smp;
map<int,string> imp;
typedef int __map_t[MAXN][MAXN];
__map_t a,f,pre;
int p,q,r;
void floyd(int n)
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(f[i][j]>f[i][k]+f[k][j])
				{
					f[i][j]=f[i][k]+f[k][j];
					pre[i][j]=pre[k][j];
				}
}
void putWay(int st,int en)
{
	if(st==en){cout<<imp[st];return;}
	putWay(st,pre[st][en]);
	cout<<"->"<<'('<<a[pre[st][en]][en]<<')'<<"->"<<imp[en];
}
int main()
{
	for(int i=0;i<MAXN;i++) 
		for(int j=0;j<MAXN;j++) f[i][j]=a[i][j]=MAXI,pre[i][j]=-1;
	for(int i=0;i<MAXN;i++) f[i][i]=a[i][i]=0;
	for(int i=0;i<=MAXN;i++) pre[i][i]=i;
	string s,s2;
	cin>>p;//cin.get();
	for(int i=1;i<=p;i++) 
	{
		cin>>s;
		smp[s]=i;imp[i]=s;
	}
	cin>>q;//cin.get();
	for(int i=1;i<=q;i++)
	{
		cin>>s>>s2;
		int l;cin>>l;
		int u=smp[s],v=smp[s2];
		if(a[u][v]>l)
			a[u][v]=l;a[v][u]=l;
	}
	for(int i=1;i<=p;i++)
		for(int j=1;j<=p;j++) {f[i][j]=a[i][j];if(a[i][j]!=MAXI) pre[i][j]=i;}
	floyd(p);
	cin>>r;//cin.get();
	for(int i=0;i<r;i++)
	{
		cin>>s>>s2;
		int u=smp[s],v=smp[s2];
		putWay(u,v);
		cout<<endl;
	}
	return 0;
}	
