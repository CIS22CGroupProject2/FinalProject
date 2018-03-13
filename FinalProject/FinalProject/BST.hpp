#pragma once
//***********************************************
// this class is BST w/ the standard
// operations.
//***********************************************

#include "BSTNode.hpp"
#include <iostream>

using namespace std;


template<class T>
class BST : protected Node<T>
{
private:
	int count;
	Node<T> *root;

public:
	//defautl constructor
	BST() { root = nullptr; count = 0; }


	// getters and setters for root
	void setRoot(Node<T> * r) { root = r; }
	Node<T> *getRoot() { return root; }

	// returns count of nodes in BST
	int getCount() { return count; }

	// check if BST is empty
	bool isEmpty();

	//check if there is left/right child
	bool Left(Node<T> *check);
	bool Right(Node<T> *check);

	// add new data
	void append(Node<T> *nodeptr, Node<T> *newNode);
	// to create a new node
	void addNode(T d);
	/*
	// to display an inorder traversal
	void displayInOrder(Node<T> *nodePtr)  ;

	// to display an inorder traversal
	//void InOrder()
	//{displayInOrder(root);}


	void displayPreOrder() const
	{displayPreOrder(root);}


	// display a post order traversal of BST
	//void displayPostOrder(Node<T> *nodePtr) const
	void displayPostOrder() const
	{displayPostOrder(root); }

	*/
	// for breadth traversal
	void breadth();
	void breadthTraversal(Node<T> *nodePtr);

	// search for data
	bool Search(T x);

	// deletion in BST
	void remove(T val);
	void deleteNode(T val, Node<T> *nodePtr);
	void deletion(Node<T> *nodePtr);

	//destructor
	// deletes BST
	~BST()
	{
		Node<T> *nodePtr;
		nodePtr = root;


		if (!isEmpty())
		{
			destroyRec(nodePtr);
		}
	}

	void destroyRec(Node<T> *nodeptr)
	{
		if (nodeptr)
		{
			destroyRec(nodeptr->getLeft());
			destroyRec(nodeptr->getRight());
			delete nodeptr;
			nodeptr = nullptr;

		}
	}
};



template<class T>
bool BST<T>::isEmpty()
{
	// if root is pnting to nullptr
	// return true
	if (!root)
		return true;

	// if not 
	// return false
	else
		return false;
}

template<class T>
bool BST<T>::Left(Node<T> *check)
{
	// if there is a left child 
	// return true
	if (!check->getLeft())
		return true;
	else
		return false;

}

template<class T>
bool BST<T>::Right(Node<T> *check)
{
	// if there is a right child
	// return true
	if (!check->getRight())
		return true;
	else
		return false;
}
//**************************
// creates a new node
// to store into BST
// and uses the rcursive
// method append to add a 
// new node into tree.
//**************************
template<class T>
void BST<T>::addNode(T d)
{
	Node<T> *newNode;

	// create new node and store data 
	newNode = new Node<T>(d);

	// call append to add node in approp. place.
	append(root, newNode);
	// increment count
	count++;
}

//*********************************************
// defined append functioin recursively
// to add new nodes in BST in approp.
//place.
//**********************************************
template<class T>
void BST<T>::append(Node<T> *nodePtr, Node<T> *newNode)
{
	// if BST is empty 
	// assign root the new value/data
	if (nodePtr == nullptr)
	{
		nodePtr = newNode;
	}
	else
	{
		if (nodePtr->getData() < newNode->getData())
		{
			// call recursively
			// with next value.
			if (nodePtr->getLeft() != nullptr)
			{
				append(nodePtr->getLeft(), newNode);
			}
			else
			{
				nodePtr->setLeft(newNode);
				nodePtr = newNode;
			}
		}
		else
		{
			// call recursively
			// with next value.
			if (nodePtr->getRight() != nullptr)
			{
				append(nodePtr->getRight(), newNode);
			}
			else
			{
				nodePtr->setRight(newNode);
				nodePtr = newNode;
			}
		}
	}
}

//****************************************
// to display inorder traversal
//****************************************
/*
template<class T>
void BST<T>::displayInOrder(Node<T> *nodePtr)
{
if (nodePtr)
{
// recusive call to left branch
displayInOrder(nodePtr->getLeft());

//print out display
cout << nodePtr->getData() << endl;

// recursive call to right branch
displayInOrder(nodePtr->getRight());
}
}
//*****************************************
// to display a pre order traversal
//*****************************************

template<class T>
void BST<T>::displayPreOrder(Node<T> *nodePtr) const
{
if (nodePtr)
{
cout << nodePtr->getData() << endl;
displayPreOrder(nodePtr->getLeft());
displayPreOrder(nodePtr->getRight());

}
}

//*****************************************
// to display a post order traversal
//*****************************************
template<class T>
void BST<T>::displayPostOrder(Node<T> *nodePtr) const
{
if (nodePtr)
{
displayPreOrder(nodePtr->getLeft());
displayPreOrder(nodePtr->getRight());
cout << nodePtr->getData() << endl;
}
}
//*****************************************
// to search if a value/data exists within
// the BST. returns true/false.
//*****************************************
*/
template<class T>
bool BST<T>::Search(T x)
{
	Node<T> *newNode = root;

	while (nodePtr)
	{
		if (nodePtr->getData() == x)
		{
			return true;
		}
		else
		{
			if (x < nodePtr->getData())
			{
				nodePtr->getLeft();
			}
			else
			{
				nodePtr->getRight();
			}
		}// end if
	}// end while
	return false;
}
//*****************************************
// removes node from tree
// by calling deleting node.
//*****************************************
template<class T>
void BST<T>::remove(T val)
{
	deleteNode(val, root);
}
//**********************************************
// find the node in the binary tree
// and when found, calls the deletion function
// that will delete the node and redefine the 
// tree appropiately.
//*****************************************
template<class T>
void BST<T>::deleteNode(T val, Node<T> *nodePtr)
{
	if (val < nodePtr->getData())
	{
		deleteNode(val, nodePtr->getLeft());

	}
	else if (val > nodePtr->getData())
	{
		deleteNode(val, nodePtr->getRight());
	}
	else
	{
		deletion(nodePtr);
	}
}
//******************************************
// deletes node in BST and reattaches nodes
// in tree to fit appropiately
// by finding he smallest in the left tree
//******************************************
template<class T>
void BST<T>::deletion(Node<T> *nodePtr)
{
	Node<T> *temp = nullptr;

	if (nodePtr == nullptr)
	{
		cout << "Cannot delete empty node....." << endl;
		return;
	}
	// if only left child
	else if (nodePtr->getRight() == nullptr)
	{
		temp = nodePtr;
		nodePtr = nodePtr->left;
		delete temp;
		temp = nullptr;
	}
	// if only right child
	else if (nodePtr->getLeft() == nullptr)
	{
		temp = nodePtr;
		nodePtr = nodePtr->right;
		delete temp;
		temp = nullptr;
	}
	// if rooot has both left and right children
	else
	{
		// get right node
		temp = nodePtr->right();

		// get to end of left
		while (nodePtr->getLeft)
		{
			temp = nodePtr->left;

		}
		// reattach left subtree
		temp->left = nodePtr->left;
		temp = nodePtr;
		// reattahe right subtre

		temp->right = nodePtr->right;
		delete temp;
		temp = nullptr;


	}

}
//**********************************************
// to traverse tree breadth/level method
//**********************************************

template<class T>
void BST<T>::breadthTraversal(Node<T> *nodePtr)
{

	if (nodePtr == nullptr)
	{
		return;
	}
	else
	{
		cout << nodePtr->getLeft() << endl;
		cout << nodePtr->getRight() << endl;

	}
}
template<class T>
void BST<T>::breadth()
{

	breadthTraversal(root);
}