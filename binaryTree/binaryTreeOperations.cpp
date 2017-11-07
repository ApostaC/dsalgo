#include <iostream>
#define MAXN 110
using namespace std;
struct Node
{
	int l,r,p;
	Node(int ll=-1,int rr=-1,int pp=-1):l(ll),r(rr),p(pp){}
	void setl(int ll){l=ll;}
	void setr(int rr){r=rr;}
	void setp(int pp){p=pp;}
	void exchange(){int t=l;l=r;r=t;}
};
int t,n,m;
Node nodes[MAXN];
void swap(int a,int b)
{
	int pa=nodes[a].p,pb=nodes[b].p;
	Node & npa=nodes[pa], & npb=nodes[pb];
	if(pa==pb)
	{
		npa.exchange();
		return;
	}
	if(npa.l==a) npa.setl(b);
	else npa.setr(b);
	if(npb.l==b) npb.setl(a);
	else npb.setr(b);
}
int query(int x)
{
	Node & nd=nodes[x];
	if(nd.l==-1) return x;
	return query(nd.l);
}
void operate()
{
	int a,x,y;
	cin>>a;
	if(a==1)
	{
		cin>>x>>y;swap(x,y);
	}
	if(a==2)
	{
		cin>>x;cout<<query(x)<<endl;
	}
}
int main1()
{
	for(int i=0;i<MAXN;i++) nodes[i]=Node();
	cin>>n>>m;
	int x,y,z;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>z;
		Node & nd=nodes[x];
		nd.setl(y);nd.setr(z);
		nodes[y].setp(x);nodes[z].setp(x);
	}
	for(int i=0;i<m;i++) operate();
	return 0;
}
int main()
{
	cin>>t;
	for(int i=0;i<t;i++)
		main1();
	return 0;
}
