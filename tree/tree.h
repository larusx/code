#ifndef _TREE_H
#define _TREE_H
template<class Val>
struct node
{
	typedef node<Val>* node_ptr;
	node_ptr left;
	node_ptr right;
	node<Val>(){left=0;right=0;}
	Val value;
};

template<class Val>
class btree
{
	typedef typename node<Val>::node_ptr node_ptr;
	node_ptr tree_node; 
	node_ptr tree_root;
public:
	btree<Val>(){tree_node=0;}
	void insert(const Val& value);
	static void print1(node_ptr root);
	static void print2(node_ptr root);
	static void print3(node_ptr root);
	node_ptr getroot();
	void print2();
	void print3();
};
#endif
