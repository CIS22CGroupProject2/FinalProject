<<<<<<< HEAD
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

	//check if there is left/right child
	bool Left(Node<T> *check);
	bool Right(Node<T> *check);

	// add new data
	void append(T x, Node<T> *root);



	


};



template<class T>
bool BST<T>::isEmpty()
{
	// if root is pnting to nullptr
	// return true
	if(!root)
		return true;

	// if not 
	// return false
	else 
		return false
}

template<class T>
bool BST<T>::Left(Node<T> *check)
{
	// if there is a left child 
	// return true
	if(!check->getLeft)
		return true;
	else
		return false;

}

template<class T>
bool BST<T>::Right(Node<T> *check)
{
	// if there is a right child
	// return true
	if(!check->getRight)
		return true;
	else
		return false;
}

//*********************************************
// defined append functioin recursively
// to add new nodes in BST in approp.
//place.
//**********************************************
template<class T>
void BST::append(T x, Node<T> *root)
{
	// if BST is empty 
	// assign root the new value/data
	if(root ==nullptr)
	{
		root->data = x;
		root->left = nullptr;
		root->right = nullptr;
	}
	else
	{
		if(x < root->data)
		{
			// call recursively
			// with next value.
			append(x, root->left);
		}
		else
		{
			// call recursively
			// with next value.
			append(x, root->right);
		}
	}





}
















=======
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

	//check if there is left/right child
	bool Left(Node<T> *check);
	bool Right(Node<T> *check);

	// add new data
	void append(T x, Node<T> *root);



	


};



template<class T>
bool BST<T>::isEmpty()
{
	// if root is pnting to nullptr
	// return true
	if(!root)
		return true;

	// if not 
	// return false
	else 
		return false
}

template<class T>
bool BST<T>::Left(Node<T> *check)
{
	// if there is a left child 
	// return true
	if(!check->getLeft)
		return true;
	else
		return false;

}

template<class T>
bool BST<T>::Right(Node<T> *check)
{
	// if there is a right child
	// return true
	if(!check->getRight)
		return true;
	else
		return false;
}

//*********************************************
// defined append functioin recursively
// to add new nodes in BST in approp.
//place.
//**********************************************
template<class T>
void BST::append(T x, Node<T> *root)
{
	// if BST is empty 
	// assign root the new value/data
	if(root ==nullptr)
	{
		root->data = x;
		root->left = nullptr;
		root->right = nullptr;
	}
	else
	{
		if(x < root->data)
		{
			// call recursively
			// with next value.
			append(x, root->left);
		}
		else
		{
			// call recursively
			// with next value.
			append(x, root->right);
		}
	}





}
















>>>>>>> 0241a52b215f12a4112259cae0e48493abf7d5a0
