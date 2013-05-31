#include <iostream>
#include "tree.h"
#include "tree.cpp"
using namespace std;
int main()
{
	btree<int> mytree;
	mytree.insert(3);
	mytree.insert(2);
	mytree.insert(5);
	mytree.insert(4);
	mytree.insert(6);
	mytree.print1(mytree.getroot());
	mytree.print2(mytree.getroot());
	mytree.print3(mytree.getroot());
	return 0;

}
