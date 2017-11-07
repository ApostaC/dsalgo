#include <iostream>
#include <cstring>
using namespace std;
class Node{
public:
    char d;
    Node* lft, *rht;
    Node(const char v):d(v){
        lft= rht = NULL;
    }
};
Node* level[100]; 
void postOrder(Node* root){
    if (root!= NULL){
        postOrder(root->lft);
        postOrder(root->rht);
        cout<<root->d;
    }
}

void midOrder(Node* root){ 
    if (root!=NULL) {
        midOrder(root->lft);
        cout<<root->d;
        midOrder(root->rht);
    }

}
int main(){
    int n;
    cin>>n;
    int l;
    int pt=0;
    while(n--){
        string s;
        Node * tmp;
        Node * root=NULL;
        while(cin>>s && s!="0"){
            l= (int)s.length()-1; 
            tmp = new Node(s[l]);
            if (tmp->d!='*') cout<<tmp->d; 
            if(l==0){
                level[l]=tmp;
                if (root==NULL) root = tmp;
                continue;
            }
            if(l==pt+1){
                if (tmp->d =='*'){ level[pt]->lft=NULL;}
                else {level[pt]->lft= tmp;}
                level[l]=tmp;
                pt=l;
                continue;
            }
            if (l<=pt){ 
                level[l]=tmp;
                level[l-1]->rht=tmp;
                pt=l;
                continue;
			}
        }
        cout<<endl;
        if (root!=NULL){
			postOrder(root); cout<<endl;
			midOrder(root); cout<<endl;
        }
        cout<<endl;
        root=NULL;
        pt =0;
    }
    return 0;
}
