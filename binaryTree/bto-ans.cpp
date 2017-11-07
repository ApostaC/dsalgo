#include<iostream>

using namespace std;

struct Node{
	int tag;
	int left;
	int right;
	Node(int n = 0){
		tag = n;
		left = -1;
		right = -1;
	}
	Node& operator=(const Node& t){
		tag = t.tag;
		left = t.left;
		right = t.right;
		return *this;
	}
};

int main()
{
	int T = 0;
	cin >> T;
	while (T--){
		int nn, opn;
		cin >> nn >> opn;
		Node *tree = new Node[nn];
		for (int i = 0; i < nn; i ++){
			int tag, left, right;
			cin >> tag >> left >> right;
			tree[tag].tag = tag;
			tree[tag].left = left;
			tree[tag].right = right;
		}
		for (int i = 0; i < opn; i ++){
			int op;
			cin >> op;
			if (op == 1){
				int tag1, tag2;
				int pos1, pos2;
				cin >> tag1 >> tag2;
				for(int j = 0; j < nn; j ++){
					if (tree[j].tag == tag1){
						pos1 = j;
					}
					else if (tree[j].tag == tag2){
						pos2 = j;
					}
				}
				Node t = tree[pos1];
				tree[pos1] = tree[pos2];
				tree[pos2] = t;
			}
			else if (op == 2){
				int ttag;
				cin >> ttag;
				for (int j = 0; j < nn; j ++){
					if (tree[j].tag == ttag){
						while(tree[j].left != -1){
							j = tree[j].left;
						}
						cout << tree[j].tag << endl;
						break;
					}
				}
			}
		}
		delete[] tree;
	}
	return 0;
}

