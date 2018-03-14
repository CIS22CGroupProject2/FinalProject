#pragma once
#pragma once

//************************************************************************************************************************************************************
//Node class has two protected variables, and a constructor and destructor.
//The constructor initilizes data and the node pointer assigned to the next address of another node to null.
//There is getData function of type T, that will return a type assigned / defined in main.And a setNext and getNext functions.
//The getNext function has a return type Node<T> * and setNext is defind as void.
//This class is used furthur in the Linked List class where it connects each node in a linnear list of nodes.
//***************************************************************************************************************************************************************
#ifndef LLNode_hpp
#define LLNode_hpp

//#include <stdio.h>


template <class T>
class LLNode
{
protected:
	// data and pointer to the next node 
	T data;
	LLNode<T> *pNext;
public:
	//constructor
	// initilizes data nd Pnext
	LLNode(T x) { data = x; pNext = nullptr; }
	//returns data
	T getData() { return data; }
	// return next pointer  
	LLNode<T> *getNext() { return pNext; }
	// sets next pointer
	void setNext(LLNode<T> *next) { pNext = next; }

	//destructor
	~LLNode() {}

};
#endif 
