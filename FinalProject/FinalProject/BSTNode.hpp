#pragma once
//**************************
// Node for BST 
//**************************

template<class T> 
class BSTNode
{
private:
	T data;
	BSTNode<T> *left;
	BSTNode<T> *right;

public:
	//default constructor
	BSTNode() {}
	//constructor
	BSTNode(T x) { data = x; left = nullptr; right = nullptr; }
	
	T getData() { return data; }
	
	//get and setters for left child
	void setLeft(BSTNode<T> *l) { left = l; }
	BSTNode<T> *getLeft() { return left; }

	//getters and setters for right child
	void setRight(BSTNode<T> *r) { right = r; }
	BSTNode<T> *getRight() { return right; }


	//destructor
	virtual ~BSTNode() {}
};