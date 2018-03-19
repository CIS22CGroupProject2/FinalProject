#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


#ifndef Hash_h
#define Hash_h

class Hash
{
private:

	static const int tableSize = 70;
	struct player
	{
		string name;
		int matches, wins, losses, winPercent;
		player* next;
	};
	player* hashTable[tableSize];
public:
	Hash();
	int hash(string key);
	void addItem(string name, int matches, int wins, int losses, int winPercent);
	int numberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void FindPlayer(string name);
	void removePlayer(string name);
	void printEachName();
	player* returnPlayerPointer(string name);
	
	~Hash()
	{
		player* Ptr;
		for (int i = 0; i<tableSize; i++)
		{
			while (hashTable[i] != NULL)
			{
				Ptr = hashTable[i];
				hashTable[i] = hashTable[i]->next;
				delete Ptr;
			}
		}
	}
	


	/*class iterator
	{
	private:
		List<HashMapNode<T>*>* mapNodes;
		int position;
		unsigned int operations;
	public:
		iterator() {
			mapNodes = nullptr;
			position = 0;
		}
		iterator(List<HashMapNode<T>*>* ptr, int pos) {
			mapNodes = ptr;
			position = pos;
		}
		iterator operator++() { iterator i = *this; position++; return i; }
		iterator operator++(int junk) { position++; return *this; }
		HashMapNode<T>& operator*() { return *((*mapNodes)[position]); }
		HashMapNode<T>* operator->() { return (*mapNodes)[position]; }
		bool operator==(const iterator& rhs) { return position == rhs.position; }
		bool operator!=(const iterator& rhs) { return position != rhs.position; }
	};*/

};


#endif /* Hash_h */