#pragma once
#ifndef BST_hpp
#define BST_hpp
//***********************************************
// this class is BST w/ the standard
// operations.
//***********************************************

#include "BSTNode.hpp"
#include "LLNode.hpp"
#include "Queue.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


class BST : protected BSTNode
{
private:
	int count;
	BSTNode *root;

public:
	//defautl constructor
	BST() { root = nullptr; count = 0; }

	
	// getters and setters for root
	BSTNode *getRoot() { return root; }

	// returns count of nodes in BST
	int getCount() { return count; }

	// check if BST is empty
	bool isEmpty();

	// add new data to BST
	void appendByName(string n, int m, int w, int l, int wp);
	void appendByWins(string n, int m, int w, int l, int wp);

	void PreOrder(BSTNode *nodePtr, int level = 0) const;

	// display a post order traversal of BST
	void displayPostOrder() const
	{
		PostOrder(root);
	}

	void PostOrder(BSTNode *nodePtr) const;
	void displayPreOrder() const
	{
		PreOrder(root);
	}
	void displayInOrder() const
	{
		inOrder(root);
	}
	void inOrder(BSTNode *nodePtr) const;


	// for breadth traversals
	void breadth();

	// search for data
	bool SearchByName(string n);

	// deletion in BST
	bool remove(string n);
	bool deleteNode(string n, BSTNode *nodePtr);
	void deletion(BSTNode *nodePtr);

	//destructor
	// deletes BST
	~BST()
	{
		BSTNode *nodePtr;
		nodePtr = root;


		if (!isEmpty())
		{
			destroyRec(nodePtr);
		}
	}

	void destroyRec(BSTNode *nodeptr)
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

//*****************************************************
// this function checks if the entire BST is empty
//*****************************************************
bool BST::isEmpty()
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


//********************************************************************
// add new nodes in appropoates place in accordance of tree structure
// according to ascii values of names
//********************************************************************
void BST::appendByName(string n, int m, int w, int l, int wp)
{
	if (!root)
	{
		root = new BSTNode(n, m, w, l, wp);
		count++;
		return;
	}

	BSTNode *temp = root;
	BSTNode *parent = nullptr;

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
		parent->setLeft(new BSTNode( n,  m,  w, l,  wp));
		count++;
	}
	else
	{
		parent->setRight(new BSTNode( n,  m,  w,  l,  wp));
		count++;
	}

}


//********************************************************************
// add new nodes in appropoates place in accordance of tree structure
// according to value of wins
//********************************************************************
void BST::appendByWins(string n, int m, int w, int l, int wp)
{
	if (!root)
	{
		root = new BSTNode(n, m, w, l, wp);
		count++;
		return;
	}

	BSTNode *temp = root;
	BSTNode *parent = nullptr;

	while (temp)
	{
		parent = temp;
		if (w < temp->getWins())
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
	}

	if (w < parent->getWins())
	{
		parent->setLeft(new BSTNode(n, m, w, l, wp));
		count++;
	}
	else
	{
		parent->setRight(new BSTNode(n, m, w, l, wp));
		count++;
	}

}


//*****************************************
// to display a post order traversal
//*****************************************
void BST::PostOrder(BSTNode *nodePtr) const
{

	if (nodePtr)
	{
		PostOrder(nodePtr->getLeft());
		PostOrder(nodePtr->getRight());

		// write to commad scrn
		cout << nodePtr->getName() << endl;
		cout << nodePtr->getMatches() << endl;
		cout << nodePtr->getWins() << endl;
		cout << nodePtr->getLosses() << endl;
		cout << nodePtr->getWinPercent() << endl;
	}
}

void BST::inOrder(BSTNode *nodePtr) const
{
	if (nodePtr)
	{
		inOrder(nodePtr->getLeft());

		cout << std::left
			<< setw(20) << nodePtr->getName() << " Matches: "
			<< setw(4) << nodePtr->getMatches() << " Wins: "
			<< setw(4) << nodePtr->getWins() << " Losses: "
			<< setw(4) << nodePtr->getLosses() << " Win Percentage: "
			<< setw(4) << nodePtr->getWinPercent() << "%";
		cout << endl;
		inOrder(nodePtr->getRight());

		
	}

}

//*****************************************
// to display a pre order traversal
//*****************************************
void BST::PreOrder(BSTNode *nodePtr, int level) const
{
	level++;
	if (nodePtr)
	{
		for (int x = 0; x < level; x++)
		{
			cout << " ";
		}
		cout << nodePtr->getName();
		cout << " Wins: ";
		cout << nodePtr->getWins() << endl;

		PreOrder(nodePtr->getLeft(), level);
		PreOrder(nodePtr->getRight(), level);

	}
}

//*****************************************
// to search if a value/data exists within
// the BST. returns true/false.
//*****************************************

bool BST::SearchByName(string n)
{
	BSTNode *nodePtr = root;

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
bool BST::remove(string n)
{
	bool x = deleteNode(n, root);
	return x;
}
//**********************************************
// find the node in the binary tree
// and when found, calls the deletion function
// that will delete the node and redefine the 
// tree appropiately.
//*****************************************
bool BST::deleteNode(string n, BSTNode *nodePtr)
{
	bool x = false;
	if (n < nodePtr->getName() )//&& nodePtr != NULL)
	{
		x = deleteNode(n, nodePtr->getLeft());

	}
	else if (n > nodePtr->getName())// && nodePtr != NULL)
	{
		x = deleteNode(n, nodePtr->getRight());
	}
	else
	{
		deletion(nodePtr);
		x = true;
	}
	return x;
}
//******************************************
// deletes node in BST and reattaches nodes
// in tree to fit appropiately
// by finding he smallest in the left tree
//******************************************
void BST::deletion(BSTNode *nodePtr)
{
	BSTNode *temp = nullptr;

	if (nodePtr == nullptr)
	{
		cout << "Cannot delete empty node....." << endl;
		return;
	}
	// if only left child
	else if (nodePtr->getRight() == nullptr)
	{
		temp = nodePtr;
		nodePtr = nodePtr->getLeft();
		delete temp;
		temp = nullptr;
	}
	// if only right child
	else if (nodePtr->getLeft() == nullptr)
	{
		temp = nodePtr;
		nodePtr = nodePtr->getRight();
		delete temp;
		temp = nullptr;
	}
	// if rooot has both left and right children
	else
	{
		// get right node
		temp = nodePtr->getRight();

		// get to end of left
		while (temp->getLeft() !=nullptr)
		{
			temp = nodePtr->getLeft();
			
		}
		// reattach left subtree
		temp->setLeft(nodePtr->getLeft());
		//temp->left = nodePtr->left;
		temp = nodePtr;
		// reattach right subtre
		temp->setRight(nodePtr->getRight());
		//temp->getRight() = nodePtr->getRight();
		delete temp;
		temp = nullptr;


	}

}
//**********************************************
// to traverse tree breadth/level method
//**********************************************
void BST::breadth()
{
	//ofs << "this is breadth traversal of your data" << endl;

	// Base Case
	if (root == nullptr)
		return;

	// Create an empty queue for level order tarversal
	Queue<BSTNode *> q;

	BSTNode *temp = root;
	// Enqueue Root and initialize height
	q.enqueue(temp);

	while (q.getNum() != 0)
	{
		// Print front of queue and remove it from queue
		temp = q.front();
		cout << "*************************************************" << endl;
		cout << "Player name: "<< temp->getName() << endl;
		cout << "Wins: " << temp->getWins() << endl;
		cout << "Losses: " << temp->getLosses() << endl;
		cout << "Matches played: " << temp->getMatches() << endl;
		cout << "Win Percent: " << temp->getWinPercent() << endl;
		
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





#endif