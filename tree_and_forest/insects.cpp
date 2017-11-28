#include <iostream>
#define MAXN 2020
using namespace std;
int pre[2*MAXN];
void package(int x,int r){if (x!=r){int temp=pre[x];pre[x]=r;package(temp,r);}}
int find(int x){int r=x;while(r!=pre[r])r=pre[r];package(x,r);return r;}
void join(int x,int y){pre[find(x)]=find(y);}
bool query(int x,int y){return find(x)==find(y);}
int h(int x,int n){return x+n;}
void out(int t,bool f)
{
	cout<<"Scenario #"<<t<<":"<<endl;
	if(f) cout<<"No suspicious bugs found!"<<endl;
	else cout<<"Suspicious bugs found!"<<endl;
	cout<<endl;
}
void main1(int t)
{
	int n,op;
	cin>>n>>op;
	for(int i=0;i<2*n+10;i++) pre[i]=i;
	int a,b;
    bool flag=true;
	for(int i=0;i<op;i++)
	{
		scanf("%d %d",&a,&b);
		join(a,h(b,n));join(b,h(a,n));
		if(query(a,b)) 
		{
			flag=false;
		}
	}
	out(t,flag);
}	
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++) main1(i+1);
	return 0;
}
