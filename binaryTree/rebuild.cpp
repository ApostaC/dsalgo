#include <iostream>
#include <string.h>
#define N (1<<17)+10
using namespace std;
int p[N],m[N],pos[N],t[N];
int cnt;

void rebuild(int ml,int mr,int pl,int pr,int curr)
{
	int val=p[pr];
	t[curr]=val;
	int pos_m=pos[val];
	int len=pos_m-ml;
	if(len<0) return;
	if(len>0)
	{
		rebuild(ml,pos_m-1,pl,pl+len-1,curr*2);
	}
	if(pos_m+1<=mr)
	{
		rebuild(pos_m+1,mr,pl+len,pr-1,curr*2+1);
	}
}
void preTravel(int curr)
{
	if(t[curr]<0) return;
	cout<<t[curr]<<" ";
	preTravel(curr*2);
	preTravel(curr*2+1);
}
int main()
{
	memset(t,-1,sizeof(t));
	cnt=0;
	int a;char c;
	while(cin>>a)
	{
		m[++cnt]=a;
		pos[a]=cnt;
		c=cin.peek();
		if(c=='\n') break;
	}
	for(int i=1;i<=cnt;i++) cin>>p[i];
	rebuild(1,cnt,1,cnt,1);
	preTravel(1);
	return 0;
}
