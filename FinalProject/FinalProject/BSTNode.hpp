#pragma once
//**************************
// Node for BST 
//**************************

template<class T> 
class Node
{
private:
	T data;
	Node<T> *left;
	Node<T> *right;

public:
	//constructor
	Node(T x) { data = x; left = nullptr; right = nullptr; }
	
	T getData() { return data; }
	
	//get and setters for left child
	void setLeft(Node<T> *l) { left = l; }
	Node<T> *getLeft() { return left; }

	//getters and setters for right child
	void setRight(Node<T> *r) { right = r; }
	Node<T> *getRight() { return right; }

	//destructor
	virtual ~Node() {}
};