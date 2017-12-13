#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;
struct Node;
typedef Node *PNode;
struct Node
{
	int data;
	PNode next;
	Node(int d):data(d),next(NULL){}
};
PNode head,curr;
int n,m;
void insert(PNode prev,int dat)
{
	PNode pn = new Node(dat);
	pn->next = prev->next;
	prev->next = pn;
}
void del(PNode prev)
{
	auto temp = prev->next;
	if(temp)
		prev->next = temp->next;
	delete temp;
}

void setUpList()
{
	cin>>n;
	int a;
	auto pcu = head;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		insert(pcu,a);
		pcu=pcu->next;
	}
}
void findAndDo(int m)
{
	PNode p = curr->next;
	while((p = curr->next))
	{
		if(p->data == m) 
		{
			del(curr);
			return;
		}
		if(p->data > m)
		{
			insert(curr,m);
			curr = curr->next;
			return;
		}
		curr=curr->next;
	}
	insert(curr,m);
}
int main()
{
	head = new Node(INT_MIN);
	setUpList();
	curr = head;
	cin>>m;int temp;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&temp);findAndDo(temp);
	}
	curr = head->next;
	while(curr)
	{
		printf("%d ",curr->data);
		curr = curr->next;
	}
	return 0;
}
