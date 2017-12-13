#include <iostream>

#define MAXN 100010
using namespace std;

int n,m;
int b[MAXN],l[MAXN];
int lowext,offset;
		//v: true->is in B 
std::pair<bool,int> getNum(int son)
{
	if(son<=n-1) return std::make_pair(true,son);
	else if (son<=offset) return std::make_pair(false,son-(n-1)+lowext);
	else return std::make_pair(false,son-offset);
}
		//v:first = winner
std::pair<int,int> buildTree(int curr)
{
	auto ls = getNum(curr*2),rs=getNum(curr*2+1);
	//fprintf(stderr,"curr = %d, ls = %d, rs = %d\n",curr,ls.second,rs.second);
	int lc,rc;
	if(ls.first == true)
		lc = buildTree(ls.second).first;
	else lc = ls.second;
	if(rs.first == true)
		rc = buildTree(rs.second).first;
	else rc = rs.second;

	//fprintf(stderr,"curr = %d, lc = %d, rc = %d\n",curr,lc,rc);

	int win,lose;		//bigger is loser
	if(l[lc] > l[rc])	//winner is r
	{
		win = rc; lose = lc;
	}
	else 
	{
		win = lc; lose = rc;
	}
	b[curr]=lose;
	return std::make_pair(win,lose);
}	

void init() //cal offset and lowext
{
	offset = 1;
	while(offset < n-1)
		offset = offset*2 + 1;
	lowext = n*2 - 1 - offset;
}

void printTree(int winner)
{
	cout<<winner<<" ";
	for(int i=1;i<=n-1;i++) cout<<l[b[i]]<<" ";
	cout<<endl;
}

//return final winner
int updateTree(int fa,int newCandi)
{
	if(fa == 0) return l[newCandi];
	int oldLoser = b[fa];
	if(l[oldLoser] > l[newCandi])
		return updateTree(fa/2,newCandi);
	else
	{
		b[fa]=newCandi;
		return updateTree(fa/2,oldLoser);
	}	
}
int getFa(int i)
{
	if (i<=lowext) return (i+offset)/2;
	else return (i-lowext+n-1)/2;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>l[i];
	init();
	//cerr<<"lowext = "<<lowext<<" , offset = "<<offset<<endl;
	int winner = l[buildTree(1).first];
	printTree(winner);
	int pos,newi;
	for(int i=0;i<m;i++)
	{
		cin>>pos>>newi;
		pos++;
		l[pos]=newi;
		winner=updateTree(getFa(pos),pos);
		printTree(winner);
		//winner = l[buildTree(1).first];
		//printTree(winner);
	}
	return 0;
}
