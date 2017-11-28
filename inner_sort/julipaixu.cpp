#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#define SQR(x) ((x)*(x))
using namespace std;
struct Point
{
	int x,y,z,id;

};
struct Pair
{
	Point p1,p2;
	Pair():p1(),p2(){}
	Pair(const Point & _p1, const Point & _p2):p1(_p1),p2(_p2){}
	double calDis() const
	{
		double dis=SQR(p1.x-p2.x)+SQR(p1.y-p2.y)+SQR(p1.z-p2.z);
		return sqrt(dis);
	}
};
bool operator<(const Point & l, const Point & r)
{
	return l.id<r.id;
}
bool operator==(const Point & l,const Point & r){return l.id==r.id;}
bool operator<(const Pair & l, const Pair & r)
{
	if(std::fabs(l.calDis()-r.calDis())<1e-6) 
	{
		if(l.p1==r.p1) return l.p2<r.p2;
		return l.p1<r.p1;
	}
	return l.calDis()>r.calDis();
}
ostream & operator<<(ostream & o, Point & p)
{
	o<<"("<<p.x<<","<<p.y<<","<<p.z<<")";
	return o;
}
ostream & operator<<(ostream & o, Pair & p)
{
	if(p.p1<p.p2)
		o<<p.p1<<"-"<<p.p2<<"="<<fixed<<setprecision(2)<<p.calDis();
	else 
		o<<p.p2<<"-"<<p.p1<<"="<<fixed<<setprecision(2)<<p.calDis();
	return o;
}
int main()
{
	int n,x,y,z;cin>>n;
	vector<Point> point_vec;
	vector<Pair> pair_vec;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y>>z;
		point_vec.push_back((Point){x,y,z,i});
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			pair_vec.push_back(Pair(point_vec[i],point_vec[j]));
	std::sort(pair_vec.begin(),pair_vec.end());
	for(auto p:pair_vec)
	{
		cout<<p<<endl;
	}
	return 0;
}
