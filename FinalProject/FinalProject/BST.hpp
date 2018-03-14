#pragma once
//***********************************************
// this class is BST w/ the standard
// operations.
//***********************************************

#include "Node.hpp"
#include "Queue.hpp"
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
	Node<T> *getRoot() { return root; }

	// returns count of nodes in BST
	int getCount() { return count; }

	// check if BST is empty
	bool isEmpty();

	//check if there is left/right child
	bool Left(Node<T> *check);
	bool Right(Node<T> *check);

	// add new data
	//void append(Node<T> *nodeptr, Node<T> *newNode);
	void append(T d);
	// to create a new node
	void addNode(T d);

	// display a post order traversal of BST
	//void displayPostOrder(Node<T> *nodePtr) const
	void displayPostOrder(ofstream &ofs) const
	{
		PostOrder(root, ofs);
	}

	void PostOrder(Node<T> *nodePtr, ofstream &ofs) const;


	// for breadth traversal
	void breadth(ofstream &ofs);

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

	if (!root)
	{
		root = newNode;
	}
	else
	{
		// call append to add node in approp. place.
		append(root, newNode);
	}
	// increment count
	count++;
}

//********************************************************************
// add new nodes in appropoates place in accordance of tree structure
//********************************************************************
template<class T>
void BST<T>::append(T d)
{
	if (!root)
	{
		root = new Node<T>(d);
		return;
	}

	Node<T> *temp = root;
	Node<T> *parent = nullptr;

	while (temp)
	{
		parent = temp;
		if (d < temp->getData())
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
	}

	if (d < parent->getData())
	{
		parent->setLeft(new Node<T>(d));
		count++;
	}
	else
	{
		parent->setRight(new Node<T>(d));
		count++;
	}

}


//*****************************************
// to display a post order traversal
//*****************************************
template<class T>
void BST<T>::PostOrder(Node<T> *nodePtr, ofstream &ofs) const
{

	if (nodePtr)
	{
		PostOrder(nodePtr->getLeft(), ofs);
		PostOrder(nodePtr->getRight(), ofs);
		cout << nodePtr->getData() << endl;
		ofs << nodePtr->getData() << endl;
	}
}
//*****************************************
// to search if a value/data exists within
// the BST. returns true/false.
//*****************************************

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
		// reattach right subtre

		temp->right = nodePtr->right;
		delete temp;
		temp = nullptr;


	}

}
//**********************************************
// to traverse tree breadth/level method
//**********************************************

template<class T>
void BST<T>::breadth(ofstream &ofs)
{
	ofs << "this is breadth traversal of your data" << endl;

	// Base Case
	if (root == nullptr)
		return;

	// Create an empty queue for level order tarversal
	Queue<Node<T> *> q;

	Node<T> *temp = root;
	// Enqueue Root and initialize height
	q.enqueue(temp);

	while (q.getNum() != 0)
	{
		// Print front of queue and remove it from queue
		temp = q.front();
		cout << temp->getData() << " ";
		ofs << temp->getData() << " ";
		q.dequeue();

		/* Enqueue left child */
		if (temp->getLeft() != nullptr)
			q.enqueue(temp->getLeft());

		/*Enqueue right child */
		if (temp->getRight() != nullptr)
			q.enqueue(temp->getRight());
	}
}