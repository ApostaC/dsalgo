#include <iostream>
#include <queue>
#define MAXN 150
typedef int Long;
using namespace std;
class Node{
public:
	static const bool LEAF=true;
	static const bool BRANCH=false;
public:
	bool tag;
	Long data;
	Node * left,* right;
	Node(int tag,int data)
	{
		left=right=NULL;
		this->tag=tag;this->data=data;
	}
	void printNode();
	static Node * join(Node * l, Node * r);
	
};
typedef Node * PNode;
struct Less{
	bool operator()(const PNode & l, const PNode & r) const
	{
		return l->data>r->data;
	}
};
typedef std::priority_queue<PNode,std::vector<PNode>,Less> PriQueue;

int n,a[MAXN];
Long ans;
PriQueue Q;
PNode buildTree()
{
	//insert leaf nodes into queue
	for(int i=0;i<n;i++) Q.push(new Node(true,a[i]));
	PNode p1,p2;
	for(int i=0;i<n-1;i++) 
	{
		p1=Q.top();Q.pop();
		p2=Q.top();Q.pop();
		Q.push(Node::join(p1,p2));
	}
	return Q.top();
}
void cal(PNode curr,int depth)
{
	if(curr->tag==Node::LEAF) ans+=(depth*curr->data);
	else
	{
		cal(curr->left,depth+1);
		cal(curr->right,depth+1);
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	PNode root=buildTree();
	cal(root,0);
	cout<<ans<<endl;
	return 0;
}
Node * Node::join(Node * l,Node* r)
{
	PNode pn=new Node(Node::BRANCH,l->data+r->data);
	pn->left=l;
	pn->right=r;
	return pn;
}
void Node::printNode()
{
	cout<<"Node value: "<<this->data<<" tag: "<<this->tag<<endl;
}
