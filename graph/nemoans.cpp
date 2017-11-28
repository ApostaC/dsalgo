#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct mp
{
	int up,down,l,r;
}mp[201][201];
struct Nemo
{
	int x,y,step;
}q[400000];
int cmp(struct Nemo a,struct Nemo b)
{
	if(a.step<b.step)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int BFS(int x,int y,int xmax,int ymax)
{
	int v[201][201],f=0,top=0;
	memset(v,0,sizeof(v));
	q[top].x=y;		
	q[top].y=x;
	q[top].step=0;
	v[x][y]=1;
	top++;
	while(f<top)
	{
		if(q[f].x<1||q[f].y>ymax||q[f].x>xmax||q[f].y<1)
		{
			return q[f].step;
		}
		if(v[q[f].x-1][q[f].y]==0&&mp[q[f].x][q[f].y].down!=-1)
		{
			q[top].x=q[f].x-1;
			q[top].y=q[f].y;
			q[top].step=q[f].step+mp[q[f].x][q[f].y].down;		
			v[q[top].x][q[top].y]=1;
			top++;
		}
		if(v[q[f].x+1][q[f].y]==0&&mp[q[f].x][q[f].y].up!=-1)
		{
			q[top].x=q[f].x+1;
			q[top].y=q[f].y;
			q[top].step=q[f].step+mp[q[f].x][q[f].y].up;
			v[q[top].x][q[top].y]=1;
			top++;
		}
		if(v[q[f].x][q[f].y+1]==0&&mp[q[f].x][q[f].y].r!=-1)
		{
			q[top].x=q[f].x;
			q[top].y=q[f].y+1;
			q[top].step=q[f].step+mp[q[f].x][q[f].y].r;
			v[q[top].x][q[top].y]=1;
			top++;
		}
		if(v[q[f].x][q[f].y-1]==0&&mp[q[f].x][q[f].y].l!=-1)
		{
			q[top].x=q[f].x;
			q[top].y=q[f].y-1;
			q[top].step=q[f].step+mp[q[f].x][q[f].y].l;
			v[q[top].x][q[top].y]=1;
			top++;
		}
		f++;
		sort(q+f,q+top,cmp);		
	}
	return -1;
}
int main()
{
	int n,m,x,y,d,t,i,i1,ymax,xmax;
	double a,b;
	scanf("%d %d",&n,&m);
	while(n!=-1||m!=-1)
	{
		memset(mp,0,sizeof(mp));
		ymax=-1;		
		xmax=-1;
		for(i=1;n>=i;i++)
		{
			scanf("%d %d %d %d",&x,&y,&d,&t);
			if(d==0)
			{
				for(i1=0;t>i1;i1++)
				{
					mp[y][x+i1].down=-1;
					mp[y-1][x+i1].up=-1;
				}
				ymax=max(ymax,y);
				xmax=max(xmax,x+i1);
			}
			else
			{
				for(i1=0;t>i1;i1++)
				{
					mp[y+i1][x].l=-1;
					mp[y+i1][x-1].r=-1;
				}
				ymax=max(ymax,y+i1);
				xmax=max(xmax,x);
			}
		}
		for(i=1;m>=i;i++)
		{
			scanf("%d %d %d",&x,&y,&d);
			if(d==0)
			{
				mp[y][x].down=1;	
				mp[y-1][x].up=1;
			}
			else
			{
				mp[y][x].l=1;
				mp[y][x-1].r=1;
			}
		}
		scanf("%lf %lf",&a,&b);
		x=a;
		y=b;
		if(x<1||y>ymax||x>xmax||y<1)
		{
			printf("0\n");	
		}
		else
		{
			printf("%d\n",BFS(x,y,xmax,ymax));
		}
		scanf("%d %d",&n,&m);
	}
	return 0;
}

