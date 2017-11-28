#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class DNA{
	private:
		string s;
		int score;
	public:
		DNA(const string & _s):s(_s),score(0)
		{
			score=getScore();
		}
		DNA()
		{
			s="";
			score=0;
		}
		int getScore() const
		{
			int ans=0;
			for(int i=0;i<s.size()-1;i++)
			{
				for(int j=i+1;j<s.size();j++)
					if(s[i]>s[j]) ans++;
			}
			return ans;
		}
		int getScore(){return score;}
		int setString(const string & _s)
		{
			s=_s;score=getScore();
		}
		string getString(){return s;}
};
bool operator<(const DNA & l, const DNA & r)
{
	return l.getScore()<r.getScore();
}
int n,l;
int main()
{
	cin>>l>>n;
	vector<DNA> v;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		v.push_back(DNA(s));
	}
	std::stable_sort(v.begin(),v.end());
	for(auto d:v)
		cout<<d.getString()<<endl;
	return 0;

}
