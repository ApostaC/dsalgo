#include <iostream>

using namespace std;

class Node{
public:
	int id;
	Node * next;
public:
	Node(int _i=-1,Node * _n=NULL):id(_i),next(_n){} 
};

class CircleList{
private:
	Node *curr,*prev;
	size_t size;
public:
	CircleList(int size)
	{
		this->size=size;
		Node *head = new Node(1);
		Node *pre,*cur;
		pre = head;
		for(int i=2;i<=size;i++)
		{
			cur = new Node(i);
			pre->next=cur;
			pre = cur;
		}
		cur->next=head;
		this->prev=cur;
		this->curr=head;
	}
	
	bool remove()
	{
		if(size==0) return false;
		prev->next=curr->next;
		delete curr;
		curr=prev->next;
		size--;
		return true;
	}

	bool iter()
	{
		if(size<=0) return false;
		curr=curr->next;
		prev=prev->next;
		return true;
	}

	Node * get()
	{
		if(size>0) return curr;
		return NULL;
	}
};

int main()
{
	int n,k;cin>>n>>k;
	CircleList cl(n);
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<k-1;j++)
			cl.iter();
		cl.remove();
	}
	cout<<cl.get()->id<<endl;
	return 0;
}
