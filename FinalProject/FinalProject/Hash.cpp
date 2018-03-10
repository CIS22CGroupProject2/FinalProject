#include "Hash.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

Hash::Hash()
{
	for (int i = 0; i < tableSize; i++)
	{
		hashTable[i] = new player;
		hashTable[i]->name = "empty";
		hashTable[i]->matches = 0;
		hashTable[i]->wins = 0;
		hashTable[i]->losses = 0;
		hashTable[i]->winPercent = 0;
		hashTable[i]->next = NULL;
	}
}

int Hash::hash(string key)
{
	int hash = 0;
	int index;

	for (int i = 0; i < 2; i++)
	{
		hash += (int)key[i];
	}
	index = hash % tableSize;



	return index;
}

void Hash::addItem(string name, int matches, int wins, int losses, int winPercent)
{
	int index = hash(name);

	if (hashTable[index]->name == "empty")
	{
		hashTable[index]->name = name;
		hashTable[index]->matches = matches;
		hashTable[index]->wins = wins;
		hashTable[index]->losses = losses;
		hashTable[index]->winPercent = winPercent;
	}
	else
	{
		player* Ptr = hashTable[index];
		player* n = new player;
		n->name = name;
		n->matches = matches;
		n->wins = wins;
		n->losses = losses;
		n->winPercent = winPercent;
		n->next = NULL;
		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

int Hash::numberOfItemsInIndex(int index)
{
	int count = 0;
	if (hashTable[index]->name == "empty")
	{
		return count;
	}
	else
	{
		count++;
		player* ptr = hashTable[index];
		while (ptr->next != NULL)
		{
			count++;
			ptr = ptr->next;
		}
	}
	return count;
}

void Hash::PrintTable()
{
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		number = numberOfItemsInIndex(i);
		cout << "*********************" << endl;
		cout << "index = " << i << endl;
		cout << hashTable[i]->name << endl;
		cout << "Number of matches played: " << hashTable[i]->matches << endl;
		cout << "Number of wins: " << hashTable[i]->wins << endl;
		cout << "Number of losses: " << hashTable[i]->losses << endl;
		cout << "Win Percentage: " << hashTable[i]->winPercent << "%" << endl;
		cout << "# of items = " << number << endl;
		cout << "*********************" << endl;
	}
}

void Hash::PrintItemsInIndex(int index)
{
	player* Ptr = hashTable[index];

	if (Ptr->name == "empty")
	{
		cout << "index = " << index << " is empty.";
	}
	else
	{
		cout << "index = " << index << " contains the following players" << endl;
		while (Ptr != NULL)
		{
			cout << "*********************" << endl;
			cout << Ptr->name << endl;
			cout << "Number of matches played: " << Ptr->matches << endl;
			cout << "Number of wins: " << Ptr->wins << endl;
			cout << "Number of losses: " << Ptr->losses << endl;
			cout << "Win Percentage: " << Ptr->winPercent << "%" << endl;
			cout << "*********************" << endl;
			Ptr = Ptr->next;
		}
	}
}
