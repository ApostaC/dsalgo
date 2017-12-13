#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;
vector<string> vs;
set<string> di;
bool deleteOne(const string & ls,const string & ss)
{
	int len=ls.length();
	for(int i=0;i<len;i++)
	{
		string temp=ls.substr(0,i)+ls.substr(i+1,len);
		if(temp==ss) return true;
	}
	return false;
}
bool addOne(const string & ls,const string & ss)
{
	return deleteOne(ls,ss);
}
bool changeOne(const string & ls,const string & ss)
{
	int diffNum=0,len=ls.length();
	for(int i=0;i<len;i++)
	{
		if(ls[i]!=ss[i]) diffNum++;
		if(diffNum>1) return false;
	}
	return (diffNum==1);
}
bool isCorrect(const string & tar, const string & dic)
{
	auto l1=tar.length(),l2=dic.length();
	if(l1==l2+1) return deleteOne(tar,dic);
	if(l1==l2) return changeOne(tar,dic);
	if(l1==l2-1) return addOne(dic,tar);
	return false;
}
int main()
{
	string s;
	while(cin>>s)
	{
		if(s=="#") break;
		di.insert(s);
		vs.push_back(s);
	}
	while(cin>>s)
	{
		if(s=="#") break;
		if(di.find(s)!=di.end())
		{
			cout<<s<<" is correct"<<endl;
			continue;
		}
		cout<<s<<":";
		for(auto ss : vs)
		{
			if(isCorrect(s,ss)) cout<<" "<<ss;
		}
		cout<<endl;
	}
	return 0;
}
