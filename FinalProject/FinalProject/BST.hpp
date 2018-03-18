#pragma once
//***********************************************
// this class is BST w/ the standard
// operations.
//***********************************************

#include "BSTNode.hpp"
#include "LLNode.hpp"
#include "Queue.hpp"
#include <iostream>
#include <string>

using namespace std;


template<class T>
class BST : protected BSTNode<T>
{
private:
	int count;
	BSTNode<T> *root;

public:
	//defautl constructor
	BST() { root = nullptr; count = 0; }

	
	// getters and setters for root
	BSTNode<T> *getRoot() { return root; }

	// returns count of nodes in BST
	int getCount() { return count; }

	// check if BST is empty
	bool isEmpty();

	//check if there is left/right child
	bool Left(BSTNode<T> *check);
	bool Right(BSTNode<T> *check);

	// add new data
	//void append(Node<T> *nodeptr, Node<T> *newNode);
	void append(string n, int m, int w, int l, int wp);
	

	// display a post order traversal of BST
	//void displayPostOrder(Node<T> *nodePtr) const
	void displayPostOrder(ofstream &ofs) const
	{
		PostOrder(root, ofs);
	}

	void PostOrder(BSTNode<T> *nodePtr, ofstream &ofs) const;


	// for breadth traversal
	void breadth();

	// search for data
	bool SearchByName(string n);

	// deletion in BST
	void remove(string n);
	void deleteNode(string n, BSTNode<T> *nodePtr);
	void deletion(BSTNode<T> *nodePtr);

	//destructor
	// deletes BST
	~BST()
	{
		BSTNode<T> *nodePtr;
		nodePtr = root;


		if (!isEmpty())
		{
			destroyRec(nodePtr);
		}
	}

	void destroyRec(BSTNode<T> *nodeptr)
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
bool BST<T>::Left(BSTNode<T> *check)
{
	// if there is a left child 
	// return true
	if (!check->getLeft())
		return true;
	else
		return false;

}

template<class T>
bool BST<T>::Right(BSTNode<T> *check)
{
	// if there is a right child
	// return true
	if (!check->getRight())
		return true;
	else
		return false;
}


//********************************************************************
// add new nodes in appropoates place in accordance of tree structure
//********************************************************************
template<class T>
void BST<T>::append(string n, int m, int w, int l, int wp)
{
	if (!root)
	{
		root = new BSTNode<T>(n, m, w, l, wp);
		count++;
		return;
	}

	BSTNode<T> *temp = root;
	BSTNode<T> *parent = nullptr;

	while (temp)
	{
		parent = temp;
		if (n < temp->getName())
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
	}

	if (n < parent->getName())
	{
		parent->setLeft(new BSTNode<T>(string n, int m, int w,int l, int wp));
		count++;
	}
	else
	{
		parent->setRight(new Node<T>(string n, int m, int w, int l, int wp));
		count++;
	}

}


//*****************************************
// to display a post order traversal
//*****************************************
template<class T>
void BST<T>::PostOrder(BSTNode<T> *nodePtr, ofstream &ofs) const
{

	if (nodePtr)
	{
		PostOrder(nodePtr->getLeft(), ofs);
		PostOrder(nodePtr->getRight(), ofs);

		// write to commad scrn
		cout << nodePtr->getName() << endl;
		cout << nodePtr->getMatches() << andl;
		cout << nodePtr->getWins() << endl;
		cout << nodePtr->getLosses() << endl;
		cout << nodePtr->getWinPercent() << endl;

		// write to output files
		ofs << nodePtr->getName() << endl;
		ofs << nodePtr->getMatches() << andl;
		ofs << nodePtr->getWins() << endl;
		ofs << nodePtr->getLosses() << endl;
		ofs << nodePtr->getWinPercent() << endl;
	}
}
//*****************************************
// to search if a value/data exists within
// the BST. returns true/false.
//*****************************************

template<class T>
bool BST<T>::SearchByName(string n)
{
	BSTNode<T> *newNode = root;

	while (nodePtr)
	{
		if (nodePtr->getName() == n)
		{
			return true;
		}
		else
		{
			if (n < nodePtr->getName())
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
void BST<T>::remove(string n)
{
	deleteNode(n, root);
}
//**********************************************
// find the node in the binary tree
// and when found, calls the deletion function
// that will delete the node and redefine the 
// tree appropiately.
//*****************************************
template<class T>
void BST<T>::deleteNode(string n, BSTNode<T> *nodePtr)
{
	if (n < nodePtr->getName())
	{
		deleteNode(n, nodePtr->getLeft());

	}
	else if (n > nodePtr->getName())
	{
		deleteNode(n, nodePtr->getRight());
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
void BST<T>::deletion(BSTNode<T> *nodePtr)
{
	BSTNode<T> *temp = nullptr;

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
void BST<T>::breadth()
{
	//ofs << "this is breadth traversal of your data" << endl;

	// Base Case
	if (root == nullptr)
		return;

	// Create an empty queue for level order tarversal
	Queue<BSTNode<T> *> q;

	BSTNode<T> *temp = root;
	// Enqueue Root and initialize height
	q.enqueue(temp);

	while (q.getNum() != 0)
	{
		// Print front of queue and remove it from queue
		temp = q.front();
		cout << temp->getData() << " ";
		//ofs << temp->getData() << " ";
		q.dequeue();

		/* Enqueue left child */
		if (temp->getLeft() != nullptr)
			q.enqueue(temp->getLeft());

		/*Enqueue right child */
		if (temp->getRight() != nullptr)
			q.enqueue(temp->getRight());
	}
}