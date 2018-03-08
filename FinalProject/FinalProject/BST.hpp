#pragma once
//***********************************************
// this class is BST w/ the standard
// operations.
//***********************************************




#include "Node.hpp"

template<class T>
class BST : protected Node
{
private:
	int count;
	Node<T> * root;

public:
	//default constructor
	BST() { root = nullptr; count = 0; }
	
	// getters and setters for root
	void setRoot(Node<T> * r) { root = r; }
	Node<T> * getRoot() { return root; }

	// returns count of nodes in BST
	int getCount() { return count; }

	// check if BST is empty
	bool isEmpty();

	


};



template<class T>
BST::isEmpty()
{
	// if root is pnting to nullptr
	// return true
	if (root!)
		return true;

	// if not 
	// return false
	else 
		return false
}