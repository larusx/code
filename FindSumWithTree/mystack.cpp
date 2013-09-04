#include<stdlib.h>
#include<iostream>
#include"mystack.h"
//using namespace std;
Stack::Stack()
{
	head=(mystack*)malloc(sizeof(mystack));
	head->data='#';
	head->next=NULL;
	sum=0;num=0;
}
void Stack::PushStack(int data)
{
	sum+=data;
	num++;
	mystack* node=(mystack*)malloc(sizeof(mystack));
	node->next=head;
	node->data=data;
	head = node;
}
int Stack::PopStack()
{
	int tmp=head->data;
	mystack* cur=head;
	head = head->next;
	free(cur);
	sum-=tmp;
	num--;
	return tmp;
}
int Stack::GetSum(){return sum;}
int Stack::GetNum(){return num;}
Stack::~Stack()
{
	mystack* cur;
	while(1)
	{
		cur=head;
		head=head->next;
		if(head != NULL)
			free(cur);
		else
		{
			free(cur);return;
		}
	}
}
void Stack::PrintStack()
{
	mystack* cur = head;
	for(int i=num;i!=0;--i)
	{
		std::cout<<cur->data<<" ";
		cur=cur->next;
	}
	std::cout<<std::endl;
}
//int main()
//{
//	Stack s;
//	s.PushStack(3);
//	s.PushStack(2);
//	s.PrintStack();
//}
