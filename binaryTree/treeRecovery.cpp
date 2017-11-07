#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Node;
typedef Node * PNode;
class Node{
	public:
		char c;
		PNode left,right;
		Node(char c)
		{
			this->c=c;left=right=NULL;
		}
		void setLeft(PNode l) { left=l; }
		void setRight(PNode r){ right=r;}
};
int pos[255];
string pre,mid;
bool init()
{
	memset(pos,0,sizeof(pos));
	bool flag=(bool)(cin>>pre>>mid);
	for(size_t i=0;i<mid.length();i++)
	{
		pos[(int)mid[i]]=i;
	}
	return flag;
}
PNode buildTree(int ml,int mr,int pl)
{
	if(ml>mr) return NULL;
	if(ml==mr) return new Node(mid[ml]);
	//ml<mr
	char root=pre[pl];
	PNode ret=new Node(root);
	int pp=pos[(int)root];
	int leftLen=pp-ml;
	ret->setLeft(buildTree(ml,pp-1,pl+1));
	ret->setRight(buildTree(pp+1,mr,pl+1+leftLen));
	return ret;
}
void postOut(PNode p)
{
	if(p==NULL) return;
	postOut(p->left);
	postOut(p->right);
	cout<<p->c;
}
int n;
int main()
{
	while(init()) 
	{
		auto p=buildTree(0,pre.length()-1,0);
		postOut(p);
		cout<<endl;
	}
}
