#include <iostream>
#include <stack>
#include <queue>
using namespace std;

char v; int f;// flag: inside or outside
class Node{ // binary-tree-node
	public:
		char data;
		Node *  left, *right;
};
stack<Node * > nodeStack;
queue<Node * > nodeQueue;
void traverse(Node * & root){ //镜面输出
	while(root){
		nodeStack.push(root);
		root=root->right;
	}
	while(!nodeStack.empty()){
		cout<<nodeStack.top()->data<<" ";
		nodeQueue.push(nodeStack.top());
		nodeStack.pop();
	}
	while(!nodeQueue.empty()){
		Node * temp=nodeQueue.front();
		nodeQueue.pop();
		if(temp->left!=NULL)
			traverse(temp->left);
	}
}
Node *  buildTree(){ //通过伪满二叉树输入树
	char v; int f;// flag: inside or outside
	cin>>v>>f;
	if(v=='$') return NULL;
	Node *  tmpnode=new Node;
	tmpnode->data=v;
	if(f==0 ) {
		tmpnode->left=buildTree();
		tmpnode->right=buildTree();
	}
	else if(f==1){
		tmpnode->left=tmpnode->right=NULL;
	}
	return tmpnode;
}
int main() {
	int num;
	cin>>num;
	Node * root;
	root=buildTree();
	traverse(root);
	return 0;
}
