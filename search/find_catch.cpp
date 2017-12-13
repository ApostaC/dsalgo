#include <iostream>
#include <cstdio>
#include <string>
#define MAXN 200010
using namespace std;

int pre[MAXN];
int t,n,m;
void init(){
	cin>>n>>m;
	for(int i=1;i<=n*2;i++) pre[i]=i;
//	cin.get();
}

void package(int x,int r){if(x!=r){int temp=pre[x];pre[x]=r;package(temp,r);}}
inline int find(int x){int r=x;while(r!=pre[r])r=pre[r];package(x,r);return r;}
inline void join(int x,int y){pre[find(x)]=find(y);}
inline bool query(int x,int y){return find(x)==find(y);}
#define h(x,n) ((x)+(n))
#define SUSP 0
#define DIFF 1
#define SAME 2
string ans[3] = {"Not sure yet.","In different gangs.","In the same gang."};
inline void out(int flag)
{
	printf("%s\n",ans[flag].c_str());
}
void debug_print(int n)
{
	for(int i=1;i<n;i++)
		cout<<pre[i]<<" ";
	cout<<endl;
}
void main1()
{
	int a,b;char c;
	for(int i=0;i<m;i++)
	{
//		scanf("%c %d %d\n",&c,&a,&b);
		cin>>c>>a>>b;
		if(c=='A')
		{
			if(query(a,b)) out(SAME);
			else if (query(a,h(b,n))) out(DIFF);
			else out(SUSP);
		}
		else if(c=='D')
		{
			join(a,h(b,n));join(b,h(a,n));
		}
		else fprintf(stderr,"get c=0x%x\n",(int)c);
		//debug_print(n*2+1);
	}
}
int main()
{
	cin>>t;
	for(int i=0;i<t;i++)
	{
		init();
		main1();
	}
	return 0;
}
