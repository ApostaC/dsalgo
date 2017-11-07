#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

enum Type{NUMB, OPER};

int level[128];
class Elem{
public:
	enum Type type;
	int data;				//operators are char, and can be represented as int too.
public:
	Elem(int data,Type t)
	{
		this->data=data;type=t;
	}
	Elem & operator+=(Elem & e) noexcept
	{
		if(this->type!=NUMB || e.type!=NUMB) throw exception();
		this->data+=e.data;
		return *this;
	}
	Elem & operator*=(Elem & e) noexcept
	{
		if(this->type!=NUMB || e.type!=NUMB) throw exception();
		this->data*=e.data;
		return *this;
	}
	Elem call(Elem & l, Elem & r) noexcept
	{
		if(this->type!=OPER || l.type!=NUMB || r.type!=NUMB) throw exception();
		Elem ret(0,NUMB);
		switch (this->data)
		{
			case '+':
				ret.data=l.data+r.data;
				break;
			case '-':
				ret.data=l.data-r.data;
				break;
			case '*':
				ret.data=l.data*r.data;
				break;
			case '/':
				ret.data=l.data/r.data;
				break;
			default:
				throw exception();
		}
		return ret;
	}
};

bool isDigit(char c)
{
	return (c>='0' && c<='9');
}

bool isOk(char c)
{
	if (isDigit(c)) return true;
	if (c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')') return true;
	return false;
}

void main1() noexcept 
{
	char t=cin.get();
	std::queue<Elem> postExpr;
	std::stack<Elem> opers;
	std::stack<Elem> numbs;
	int temp=0;
	while(isOk(t))
	{
		if(isDigit(t))
		{
			//TODO: IS DIGIT
			temp=temp*10+(t-'0');
			if( !isDigit(cin.peek()) )		//IF NEXT IS NOT DIGIT
			{
				postExpr.push(Elem(temp,NUMB));
				temp=0;
			}
		}
		else
		{
			if(t=='(') opers.push(Elem(t,OPER));				//left bracket
			else if(t==')')										//right bracket
			{
				if(opers.empty()) throw exception();			
				while(opers.top().data!='(')					//pop until left bracket
				{
					Elem e=opers.top();
					postExpr.push(e);
					opers.pop();
				}
				opers.pop();		//pop away the '('
			}
			else if(t=='+' || t=='-' || t=='*' || t=='/')
			{
				while( !opers.empty() && level[(int)(opers.top().data)]>=level[(int)t] )	//condition meet -> pop 
				{
					Elem e=opers.top();
					opers.pop();
					postExpr.push(e);
				}
				opers.push(Elem(t,OPER));
			}
			else throw exception();
		}
		t=cin.get();
//		cout<<"get t: "<<t<<" number of t is "<<(int)t<<endl;
	}		//LOOP END
//	cout<<"reading loop end!"<<endl;
	while(!opers.empty())
	{
		Elem e=opers.top();
		opers.pop();
		postExpr.push(e);
	}
//	cout<<"poping loop end!"<<endl;
	while(!postExpr.empty())
	{
		Elem e=postExpr.front();
		postExpr.pop();
		if(e.type==NUMB) numbs.push(e);
		else		//is operator
		{
			Elem r=numbs.top(); numbs.pop();	//get left
			Elem l=numbs.top(); numbs.pop();	//get right
			Elem ans=e.call(l,r);
			numbs.push(ans);
		}
	}
	cout<<numbs.top().data<<endl;

}

int main()
{
	int n;
	cin>>n;cin.get();
	level[(int)'+']=level[(int)'-']=1;
	level[(int)'*']=level[(int)'/']=2;
	level[(int)'(']=0;
	for(int i=0;i<n;i++) main1();
	return 0;
}
