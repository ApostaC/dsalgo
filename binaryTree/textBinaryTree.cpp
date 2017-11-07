#include <iostream>
#include <string>
#define MAXN 110
using namespace std;
string buffer[MAXN];
struct Node
{
	int d,l,r;
	Node(int dd=-1,int ll=-1,int rr=-1):d(dd),l(ll),r(rr){}
	void setl(int ll){l=ll;}
	void setr(int rr){r=rr;}
	void setd(int dd){d=dd;}
};

Node tree[MAXN];
int t,cnt;

void buildSubTree(int & currLine,int currLen,int &currCh)
{
	cout<<currLine<<" "<<currLen<<" "<<currCh<<" "<<buffer[currLine]<<endl;
	if(currLine>=cnt || buffer[currLine+1].length()<=currLen) 
	{
		return;
	}
	Node & curr=tree[currLine];
	curr.setd(currCh);
	currLine++;currCh++;
	string & ls=buffer[currLine];
	if(ls[ls.length()-1]!='*') 
	{
		curr.setl(currLine);
		buildSubTree(currLine,currLen+1,currCh);
	}
	currLine++;currCh++;
	string & rs=buffer[currLine];
	if(rs[rs.length()-1]!='*') 
	{
		curr.setr(currLine);
		buildSubTree(currLine,currLen+1,currCh);
	}
}
void qian(int id)
{
	if(id==-1) return;
	cout<<tree[id].d<<" ";
	qian(tree[id].l);
	qian(tree[id].r);
}
void zhong(int id)
{
	if(id==-1) return;
	zhong(tree[id].l);
	cout<<tree[id].d<<" ";
	zhong(tree[id].r);
}
void hou(int id)
{
	if(id==-1) return;
	hou(tree[id].l);
	hou(tree[id].r);
	cout<<tree[id].d<<" ";
}
void clearBuffer()
{
	for(int i=0;i<MAXN;i++) {buffer[i]="";tree[i]=Node();}
}
int main1()
{
	cnt=0;
	clearBuffer();
	do
	{
		getline(cin,buffer[cnt]);cnt++;
	}while(cin.peek()!='0');
	int crline=0,crch=0;
	buildSubTree(crline,1,crch);
	qian(0);cout<<endl;
	zhong(0);cout<<endl;
	hou(0);cout<<endl<<endl;
	return 0;
}
int main()
{
	cin>>t;cin.get();
	for(int i=0;i<t;i++) main1();
	return 0;
}
