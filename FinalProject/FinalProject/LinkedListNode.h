/*
Stephen Lee
CIS 22C
Winter 2017
Lab 2

Used Microsoft Visual Studio 2017

Node
A Node ADT which will have two attributes -
a data attribute and a pointer attribute.  Remember the Node has to be an ADT,
so that it can hold any kind of data.
You can choose to use this node as both a data and a head-pointing node
or as a simple data node in which case you will need a new head pointing node.
*/

#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H
#include <string>
template <class T>
class Node
{
public:
	T value;
	Node<T> *next;

	//******************************************************
	// Default Constructor        
	//******************************************************
	Node(T nodeValue)
	{
		value = nodeValue;
		next = nullptr;
	}

	//******************************************************
	// Destructor          
	//******************************************************
	~Node()
	{
		next = nullptr;
	}
};


#endif