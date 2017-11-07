#include <iostream>
#include <string>

using namespace std;

char mp[255];
int n;

char change(char c)
{
	char ret=c;
	if( ( c>='a' && c<'z') || (c>='A' && c<'Z') ) ret=c+1;	
	else if ('z'==c) ret='a';
	else if ('Z'==c) ret='A';
	return ret;	
}
int main()
{
	cin>>n;
	cin.get();
	for(int i=0;i<n;i++)
	{
		string s;
		getline(cin,s);
		for(int i=0;i<s.length();i++)
		{
			s[i]=change(s[i]);
		}
		cout<<s<<endl;
	}
	return 0;
}

