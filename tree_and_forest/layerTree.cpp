/*
 * read and enqueue
 * Set a virtual ROOT
 * loop
 *	read a point
 *	read next serval points
 *		save as son node
 *		enqueue
 * until no input
 */
#include <iostream>
#include <queue>
#include <list>
using namespace std;
class Node;
typedef Node* PNode;
typedef list<PNode> NodeList;
class Node
{
	public:
		char data;int numSon;
		NodeList son;
		Node(char d,int n):data(d),numSon(n){}
};
int n;
PNode root;
Node *buildTree()
{
	char c;
	int num;
	queue<PNode> Q;
	PNode ret;
	bool flag=(bool)(cin>>c>>num);
	if(!flag) return NULL;
	cout<<c<<num<<endl;
	ret=new Node(c,num);
	Q.push(ret);
	while(!Q.empty())
	{
		PNode curr=Q.front();Q.pop();
		for(int i=0;i<curr->numSon;i++)
		{
			cin>>c>>num;
			PNode newNode=new Node(c,num);
			Q.push(newNode);
			curr->son.push_back(newNode);
		}
	}
	return ret;
}
void postOrder(PNode curr)
{
	for(auto sons : curr->son) postOrder(sons);
	if(curr->data!='\0')
		cout<<curr->data<<" ";
}
int main()
{
	cin>>n;
	root=new Node('\0',0);
	PNode curr;
	for(int i=0;i<n;i++){
		curr=buildTree();
		root->son.push_back(curr);
	}
	postOrder(root);
	return 0;
}
