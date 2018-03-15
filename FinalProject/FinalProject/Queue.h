
#ifndef QUEUE_H
#define QUEUE_H 
#include "LinkedList.h"


/*
UML notation
*/




template <class T>
class Queue : protected List<T>
{
public:
	Queue();
	~Queue();
	bool enqueue(newEntry);
	bool dequeue();
	bool empty();
	void clear();
	int size();
	T front();
	T rear();


	//operator<<        
	template <class T>
	friend std::ostream& operator<< (std::ostream &foo, Queue<T> *ListPtr);
};


// Default Constructor        
template <class T>
Queue<T>::Queue()
{
	List();

}

// Destructor          
template <class T>
Queue<T>::~Queue()
{
	clear();
}

// enqueue
// insert an entry onto the queue
template <class T>
bool Queue<T>::enqueue(newEntry)
{
	return push_back(newEntry);
}

//dequeue
//remove an entry from the queue
template <class T>
bool Queue<T>::dequeue()
{
	return remove(1);
}

// empty        
// checks whether the queue is empty or not     
template <class T>
bool Queue<T>::empty()
{
	return List::empty();
}



// size         
template <class T>
int Queue<T>::size()
{
	return List::size();
}


// clear          
template <class T>
void Queue<T>::clear()
{
	List::clear();
}


//front
// returns the first element
template <class T>
T Queue<T>::front()
{
	return getValue(1);
}

//rear
//returns the last value in the queue
template <class T>
T Queue<T>::rear()
{
	return getValue(size() - 1);
}

#endif