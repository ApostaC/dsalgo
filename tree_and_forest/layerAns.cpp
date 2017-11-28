#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
struct Node
{
	char a;
	int degree;
	Node *child[26];
	Node(char c, int d) :a(c), degree(d){}
};
Node* buildTree() 
{
	char name;
	int child_num, i;
	Node *next,*cur,*root;
	queue <Node*> q_root; 
	cin >> name >> child_num;
	root = new Node(name,child_num);
	q_root.push(root);
	while (!q_root.empty())
	{
		cur = q_root.front();
		q_root.pop();
		for (i = 0; i < cur->degree; ++i)
		{
			cin >> name >> child_num;
			next = new Node(name, child_num);
			cur->child[i] = next;
			q_root.push(next);
		}
	}
	return root;
}
void postOrder(Node *root)
{
	if (root)
	{
		for (int i = 0; i < root->degree; i++)
			postOrder(root->child[i]);
		cout << root->a << ' ';
	}
}
int main()
{
	int  n;
	cin >> n;
	while (n--)
	{
		Node *root = buildTree();
		postOrder(root);
	}
	return 0;
}
