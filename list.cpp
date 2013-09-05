#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node{
	int data;
	struct node* next;
}node;
class List{
public:
	List();
	~List();
	void insert(int a);
	void remove(int a);
	void print();
private:
	node* head;
};
List::List()
{
	head=(node*)malloc(sizeof(node));
	head->next=NULL;
}
List::~List()
{
	node* cur=head->next;
	while(cur!=NULL)
	{
		free(head);
		head=cur;
		cur=cur->next;
	}
	free(head);
}
void List::insert(int a)
{
	node* cur=head;
	while(cur->next!=NULL && a>cur->next->data)
		cur=cur->next;
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=a;
	if(cur->next == NULL)
	{
		newnode->next=NULL;
		cur->next=newnode;
	}
	else
	{
		newnode->next=cur->next;
		cur->next=newnode;
	}
}
void List::print()
{
	node* cur=head->next;
	while(cur!=NULL)
	{
		cout<<cur->data<<" ";
		cur=cur->next;
	}
	cout<<endl;
}
void List::remove(int a)
{
	node* cur=head;
	node* tmp;
	while(cur->next!=NULL && cur->next->data!=a)
		cur=cur->next;
	if(cur->next->data == a)
	{
		tmp=cur->next;
		cur->next=cur->next->next;
		free(tmp);
	}
}
int main()
{
	List l;
	int arr[]={3,2,1,5,4};
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		l.insert(arr[i]);
	l.print();
	l.remove(2);
	l.remove(5);
	l.print();
	return 0;
}
