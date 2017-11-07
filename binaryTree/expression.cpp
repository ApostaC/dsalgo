#include<iostream>
#include<cstring>
#include<stack>
#include<map>
#define MAXROW 70
#define MAXCOL 300
using namespace std;
char buffer[MAXROW][MAXCOL];
map<char,int> m;
int pow(int x, int y){
	int result = 1;
	for (int i=0;i<y;++i) result*=x;
	return result;
}
struct BinaryTreeNode{
	char data;
	struct BinaryTreeNode * left;
	struct BinaryTreeNode * right;
	BinaryTreeNode(char c):data(c){
		left = NULL;
		right = NULL;
	}
};
int tree_layers(BinaryTreeNode * root){
	int left,right;
	if (!root) return 0;
	left = tree_layers(root->left);
	right = tree_layers(root->right);
	return left>right? left+1: right+1;
}
void print_tree(BinaryTreeNode * root, int root_x, int root_y, int space){
	if (!root) return;
	buffer[root_y][root_x-1] = root->data;
	if (root->left){
		buffer[root_y+1][root_x-2] = '/';
		print_tree(root->left,root_x-space,root_y+2,space>>1);
	}
	if (root->right){
		buffer[root_y+1][root_x] = '\\';
		print_tree(root->right,root_x+space,root_y+2,space>>1);
	}
}
int calc(BinaryTreeNode * root){
	if (isalpha(root->data)) return m[root->data];
	if (root->data=='+') return calc(root->left)+calc(root->right);
	if (root->data=='-') return calc(root->left)-calc(root->right);
	if (root->data=='*') return calc(root->left)*calc(root->right);
	if (root->data=='/') return calc(root->left)/calc(root->right);
	return 0;
}
int main(){
	char inexp[52], preexp[52], tmp;
	stack<char> s;
	cin >> inexp;
	int len = strlen(inexp), j=0, v_count, val;
	cin >> v_count;
	for (int i=0;i<v_count;++i){
		cin >> tmp >> val;
		m[tmp] = val;
	}
	for (int i=0;i<len;++i){
		if (isalpha(inexp[i])) preexp[j++] = inexp[i];
		else if (inexp[i]=='(') s.push(inexp[i]);
		else if (inexp[i]==')'){
			 while (s.top()!='('){
			 	preexp[j++] = s.top();
			 	s.pop();
			 }
			 s.pop();
		}
		else if (inexp[i]=='+'||inexp[i]=='-'){
			while (!s.empty()&&s.top()!='('){
				preexp[j++] = s.top();
				s.pop();
			}
			s.push(inexp[i]);
		}
		else{
			while (!s.empty()&&(s.top()=='*'||s.top()=='/')){
				preexp[j++] = s.top();
				s.pop();
			}
			s.push(inexp[i]);
		}
	}
	while (!s.empty()){
		preexp[j++] = s.top();
		s.pop();
	}
	preexp[j] = '\0';
	cout << preexp << endl; 
	BinaryTreeNode * root;
	stack<BinaryTreeNode*> s1;
	for (int i=0;i<j;++i){
		root = new BinaryTreeNode(preexp[i]);
		if(!isalpha(preexp[i])){
			root->right = s1.top();
			s1.pop();
			root->left = s1.top();
			s1.pop();
		}
		s1.push(root);
	}
	memset(buffer,' ',sizeof(buffer));
	int n = tree_layers(root);
	print_tree(root,pow(2,n-1),0,pow(2,n-2));
	int effective_lines = 0;
	for (int i=0;i<MAXROW;++i){
		j = MAXCOL -1;
		while (j>=0&&buffer[i][j]==' ') --j;
		if (j>-1){
			++effective_lines;
			buffer[i][j+1] = '\0';
		}
		else break;
	}
	for (int i=0;i<effective_lines;++i) cout << buffer[i] << endl;
	cout << calc(root) << endl;
	return 0;
}
