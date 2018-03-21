#pragma once



#ifndef Hash_h
#define Hash_h

#include <cstdlib>
#include <iostream>
#include <string>

class Hash
{
private:

	static const int tableSize = 70;
	struct player
	{
		std::string name;
		int matches, wins, losses, winPercent;
		player* next;
	};
	player* hashTable[tableSize];
public:
	player * location;
	Hash();
	int hash(std::string key);
	void addItem(std::string name, int matches, int wins, int losses, int winPercent);
	int numberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	player* Hash::FindPlayer(std::string name);
	void FindPlayer(int index, std::string name);
	void removePlayer(std::string name);
	void printEachName();
	player* returnPlayerPointer(std::string name);
	
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

};


#endif /* Hash_h */