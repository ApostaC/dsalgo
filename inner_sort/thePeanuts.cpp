#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int m,n,k,t;
int abs(int x){return x>0?x:-x;}
struct Peanut
{
	int x,y,n;
	Peanut(int xx=0,int yy=0,int nn=0):x(xx),y(yy),n(nn){}
	int backTime(){return x+1;}
	int toPickTime(const Peanut & o){return abs(o.x-x)+abs(o.y-y)+1;}
};
bool cmp(const Peanut & l,const Peanut & r)
{
	return l.n>r.n;
}
void main1()
{
	cin>>m>>n>>k;
	int tt=0,ans=0;
	int a[m][n];	
	vector<Peanut> p;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>0) p.push_back(Peanut(i,j,a[i][j]));
		}
	}
	std::sort(p.begin(),p.end(),cmp);
	tt=p[0].x+2;
	if(tt+p[0].backTime()>k) {cout <<0 <<endl;return;}
	ans+=p[0].n;
	for(int i=1;i<p.size();i++)
	{
		int temp=tt+p[i-1].toPickTime(p[i]);
//		cout<<i<<" "<<tt<<" "<<temp<<" "<<temp+p[i].backTime()<<" "<<ans<<endl;
		if(temp+p[i].backTime()<=k) {tt+=p[i-1].toPickTime(p[i]);ans+=p[i].n;}
		else break;
	}
	cout<<ans<<endl;
	return;
}
int main()
{
	cin>>t;
	for(int i=0;i<t;i++) main1();
	return 0;
}
