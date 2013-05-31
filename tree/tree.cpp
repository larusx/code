#include "tree.h"
#include <stdlib.h>
#include <iostream>
template<class Val>
void btree<Val>::insert(const Val& value)
{
	node_ptr tmp;
	bool flag;
	if(tree_node != NULL)
	{
		while(tree_node != NULL)
		{
			if(value < tree_node->value)
			{
				flag = 0;
				tmp = tree_node;
				tree_node = tree_node->left;
			}
			else
			{
				flag = 1;
				tmp = tree_node;
				tree_node = tree_node->right;
			}
		}
		tree_node = new node<Val>;
		tree_node->value = value;
		if(flag == 0)
			tmp->left = tree_node;
		else
			tmp->right = tree_node;
		tree_node = tree_root;
	}
	else
	{
		tree_node = new node<Val>;
		tree_node->value = value;
		tree_root = tree_node;
	}
}

template<class Val>
void btree<Val>::print1(node_ptr root)
{
	if(root == NULL)
	{
		return;
	}
	print1(root->left);
	std::cout<<root->value<<std::endl;
	print1(root->right);
}

template<class Val>
void btree<Val>::print2(node_ptr root)
{
	if(root == NULL)
	{
		return;
	}
	std::cout<<root->value<<std::endl;
	print2(root->left);
	print2(root->right);
}

template<class Val>
void btree<Val>::print3(node_ptr root)
{
	if(root == NULL)
	{
		return;
	}
	print3(root->left);
	print3(root->right);
	std::cout<<root->value<<std::endl;

}
template<class Val>
typename btree<Val>::node_ptr btree<Val>::getroot()
{
	return tree_root;
}
