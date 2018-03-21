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

	for (int i = 0; i < 3; i++)
	{
		hash = (hash+(int)key[i])*17;
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

Hash::player* Hash::FindPlayer(string name)
{
	int index = hash(name);
	bool foundName = false;
	int matches, wins, losses, winPercent;
	player* Ptr = hashTable[index];
	while (Ptr != NULL)
	{
		if (Ptr->name == name)
		{
			foundName = true;
			matches = Ptr->matches;
			wins = Ptr->wins;
			losses = Ptr->losses;
			winPercent = Ptr->winPercent;
			break;
		}
		Ptr = Ptr->next;
	}
	return Ptr;
}

Hash::player* Hash::returnPlayerPointer(string name)
{
	int index = hash(name);
	bool foundName = false;
	player* Ptr = hashTable[index];
	while (Ptr != NULL)
	{
		if (Ptr->name == name)
		{
			foundName = true;
			break;
		}
		Ptr = Ptr->next;
	}
	return Ptr;
}

void Hash::removePlayer(string name)
{
	int index = hash(name);
	
	player* delPtr;
	player* P1;
	player* P2;

	if (hashTable[index]->name == "empty")
	{
		cout << name << " was not found in the Hash table" << endl;
	}
	else if (hashTable[index]->name == name && hashTable[index]->next == NULL)
	{
		hashTable[index]->name = "empty";
		hashTable[index]->losses = 0;
		hashTable[index]->matches = 0;
		hashTable[index]->winPercent = 0;
		hashTable[index]->wins = 0;
		cout << name << " was removed from Hash Table" << endl;
	}
	
	else if (hashTable[index]->name == name)
	{
		delPtr = hashTable[index];
		hashTable[index] = hashTable[index]->next;
		delete delPtr;
		cout << name << " was removed from Hash Table" << endl;
	}
	else
	{
		P1 = hashTable[index]->next;
		P2 = hashTable[index];
		while (P1 != NULL && P1->name != name)
		{
			P2 = P1;
			P1 = P1->next;
		}
		if (P1 == NULL)
		{
			cout << name << " was not found in the Hash table" << endl;
		}
		else
		{
			delPtr = P1;
			P1 = P1->next;
			P2->next = P1;

			delete delPtr;
			cout << name << " was removed from Hash Table" << endl;
		}
	}
	

}

void Hash::printEachName()
{
	int index = 0;
	int i = 0;
	player* Ptr;
	while (index < tableSize)
	{
		Ptr = hashTable[index];
		if (Ptr->name == "empty")
		{
			index++;
			continue;
		}
		else
		{
			while (Ptr != NULL)
			{
				cout << i << ") " <<Ptr->name << endl;
				i++;
				Ptr = Ptr->next;
			}
		}
		index++;
	}
}
