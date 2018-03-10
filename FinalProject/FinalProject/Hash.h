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

	static const int tableSize = 69;

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

};


#endif /* Hash_h */