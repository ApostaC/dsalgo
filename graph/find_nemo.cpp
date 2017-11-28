#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#define MAXN 210
#define GRID_SIZE 200
#define MAXNN ((MAXN)*(MAXN))
#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 8
using namespace std;

int m,n;
int grid[MAXN][MAXN],way[MAXN][MAXN];
struct Door{int x,y,d;};
Door door[MAXN*MAXN+10];int dcnt;
int seed=1;
//struct Node{int id;vector<int> next;Node(int i=-1):id(i){}};
typedef vector<int> Node;
Node nd[MAXNN];int ncnt;
struct _B_type{int id,depth;};
queue<_B_type> Q;


void addObs(int,int,int);
void init()
{
	memset(grid,0,sizeof(grid));
	for(int i=1;i<MAXN;i++)
		for(int j=1;j<MAXN;j++) way[i][j]=0xf;
	for(int i=0;i<MAXN-1;i++)
	{
		addObs(0,i,1);addObs(MAXN-1,i,1);
		addObs(i,0,0);addObs(i,MAXN-1,0);
	}
	dcnt=0;ncnt=0;seed=1;
	memset(door,0,sizeof(door));
	for(int i=0;i<MAXNN;i++) nd[i].clear();
}
void addObs(int x,int y,int d)
{
	if(d==0)
	{
		way[x+1][y+1]&=(~DOWN);
		way[x+1][y]&=(~UP);
	}
	if(d==1)
	{
		way[x+1][y+1]&=(~LEFT);
		way[x][y+1]&=(~RIGHT);
	}
}
int readData()
{
	init();
	cin>>m>>n;
	if(m==-1 && n==-1) return -1;
	int x,y,d,t;
	for(int i=0;i<m;i++) 
	{
		cin>>x>>y>>d>>t;
		for(int j=0;j<t;j++)
		{
			int xx=x+j*(1-d),yy=y+j*d;
			addObs(xx,yy,d);
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>d;
		addObs(x,y,d);
		door[dcnt++]={x,y,d};
	}
	return 0;
}
void fill(int x,int y,int s);
void floodFill()
{
	seed=1;
	for(int i=1;i<=GRID_SIZE;i++)
		for(int j=1;j<GRID_SIZE;j++)
			if(grid[i][j]==0)
			{
				fill(i,j,seed);
				seed++;
			}
	ncnt=seed-1;
}
void fill(int x,int y,int seed)
{
	if(grid[x][y]!=0) return;
	grid[x][y]=seed;
	int w=way[x][y];
	if(w&UP) fill(x,y+1,seed);
	if(w&DOWN) fill(x,y-1,seed);
	if(w&LEFT) fill(x-1,y,seed);
	if(w&RIGHT) fill(x+1,y,seed);
}
void addEdge(int u,int v){nd[u].push_back(v);nd[v].push_back(u);}
void connect()
{
	for(int i=0;i<dcnt;i++)
	{
		int x=door[i].x,y=door[i].y,d=door[i].d;
		int u,v;
		if(d==0)
		{
			u=grid[x+1][y+1];v=grid[x+1][y];
		}
		if(d==1)
		{
			u=grid[x+1][y+1];v=grid[x][y+1];
		}
		addEdge(u,v);
	}
}
bool vis[MAXNN];
void cleanQueue()
{
	while(!Q.empty()) Q.pop();
}
int BFS(int start,int end)
{
	cleanQueue();
	int ret=-1;
	memset(vis,false,sizeof(vis));
	Q.push((_B_type){start,0});
	_B_type curr;
	while(!Q.empty())
	{
		curr=Q.front();Q.pop();
		int id=curr.id;
		for(auto nextNode : nd[id])
		{
			if(!vis[nextNode])
			{
				Q.push((_B_type){nextNode,curr.depth+1});
				vis[nextNode]=true;
			}
			if(nextNode==end) 
			{
				return curr.depth+1;
			}
		}
	}
	return ret;
}
void printGrid(int n)
{
	cout<<"grid: "<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<grid[i][j]<<" ";
		cout<<endl;
	}
}
void printWay(int n)
{
	cout<<"way: "<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<way[i][j]<<" ";
		cout<<endl;
	}
}
int main1()
{
	int err=0;
	err=readData();
	if(err!=0) return -1;
	floodFill();
	connect();
	float fx,fy;
	cin>>fx>>fy;
	int x=(int)ceil(fx),y=(int)ceil(fy);
	int target=grid[x][y],start=grid[1][1];
	err=BFS(start,target);
	cout<<err<<endl;
	return 0;
}
int main()
{
	while(main1()!=-1);
	return 0;
}
