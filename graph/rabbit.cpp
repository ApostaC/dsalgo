#include <iostream>
#include <algorithm>
using namespace std;

int pre[30];

void init(){for(int i=0;i<30;i++) pre[i]=i;}
void package(int x,int r){int j=x;while(pre[x]!=r){j=pre[x];pre[x]=r;x=j;}}
int find(int x){ int r=x;while(r!=pre[r]) r=pre[r]; package(x,r); return r;}
void join(int x,int y){int xx=find(x),yy=find(y);pre[xx]=yy;}
bool isSame(int x,int y){return find(x)==find(y);}	//return true if in the same group

struct Edge{
	int u,v,l;
	Edge(int uu=0,int vv=0,int ll=0):u(uu),v(vv),l(ll){}
};
bool operator<(const Edge & l, const Edge & r)
{
	return l.l<r.l;
}
Edge e[110];
int n,cnt;
int main()
{
	init();
	cnt=0;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,a1;char c;cin>>c;a=c-'A';
		cin>>a1;
		for(int j=0;j<a1;j++)
		{
			char c1;int a2,l;
			cin>>c1;a2=c1-'A';cin>>l;
			e[cnt++]=Edge(a,a2,l);
		}
	}
	sort(e,e+cnt);
	int bian=0,sum=0;
	for(int i=0;i<cnt && bian<n-1;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(!isSame(u,v))
		{
			join(u,v);bian++;sum+=e[i].l;
		}
	}
	cout<<sum;
	return 0;
}
