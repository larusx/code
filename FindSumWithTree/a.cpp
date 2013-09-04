#include<iostream>
#include"tree.h"
#include"mystack.h"
using namespace std;
void FindPath(node* root, int sum, Stack& sk)
{
	node* cur = root;
	sk.PushStack(cur->data);
	if(cur->left == NULL && cur->right == NULL)
	{
		if(sk.GetSum() == sum)
			sk.PrintStack();
	}
	else
	{
			FindPath(cur->left,sum,sk);
			FindPath(cur->right,sum,sk);
	}
	sk.PopStack();
}
int main()
{
	node* ptree = CreateTree(4);
	int a[]={2,5,1,3};
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
		InsertTree(a[i],ptree);
	//printMid(ptree);
	Stack sk;
	FindPath(ptree,9,sk);
	return 0;
}
