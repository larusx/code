#include<stdio.h>
#include<malloc.h>
#include"tree.h"
node* CreateTree(int data)
{
	node* head=(node*)malloc(sizeof(node));
	head->data=data;
	head->left=NULL;
	head->right=NULL;
	return head;
}
void InsertTree(int data, node* head)
{
	if(data > head->data)
	{
		if(head->right == NULL)
		{
			node* p=(node*)malloc(sizeof(node));
			p->data = data;
			p->left=NULL;p->right=NULL;
			head->right = p;
		}
		else
			InsertTree(data,head->right);
	}
	else if(data < head->data)
	{
		if(head->left == NULL)
		{
			node* p=(node*)malloc(sizeof(node));
			p->data = data;
			p->left=NULL;p->right=NULL;
			head->left = p;
		}
		else
			InsertTree(data,head->left);
	}
}
void printMid(node* head)
{
	if(head->left != NULL)
		printMid(head->left);
	printf("%d\n",head->data);
	if(head->right != NULL)
		printMid(head->right);
}
