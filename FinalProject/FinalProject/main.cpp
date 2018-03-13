#include <iostream>
#include "BST.hpp"

using namespace std;

int main()
{


	BST<int> tree;

	tree.addNode(3);
	tree.addNode(1);
	tree.addNode(6);
	tree.addNode(4);
	
	if (tree.isEmpty())
	{
		cout << "Is empty";
	}
	else
		cout << "not empty";

	tree.breadth();



	return 0;

}