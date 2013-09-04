#ifndef TREE_H
#define TREE_H
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node* CreateTree(int data);
void InsertTree(int data, node* head);
void printMid(node* head);
#endif
