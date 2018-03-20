#include <iostream>
#include <fstream>
#include <string>
#include "BST.hpp"
#include "LinkedList.h"
#include "Hash.h"

using namespace std;
struct player
{
	string name;
	int matches, wins, losses, winPercent;
	player* next;
};
//void BinaryTest();
void fileInput(List<struct player> &Data, Hash &hashdata);
void toBST(Hash &hashdata, BST &bstbyname, BST &bstbywins);
void deletePlayerFromHash(Hash&);
void findPlayerFromHash(Hash&);
void testBST(BST&);
bool menu(Hash &hashdata, BST &bstbyname, BST &bstbywins, List<struct player> &Data);

std::ostream& operator<< (std::ostream &foo, player value)
{
	foo << value.name;
	return foo;
}

int main()
{


	List<struct player> Data;
	Hash hashdata;
	BST bstbyname;
	BST bstbywins;
	bool inloop = true;
	fileInput(Data, hashdata);
	toBST(hashdata, bstbyname, bstbywins);
	cout << &Data;
	while (inloop == true)
	{
		inloop = menu(hashdata, bstbyname, bstbywins, Data);
	}
	
	system("pause");
}

void fileInput(List<player> &Data, Hash &hashdata)
{
	ifstream infile;
	int count = 0;
	player adding;
	char taking;
	string taking1;

	infile.open("players.txt");
	if (!infile)
	{
		cerr << "Open Failed";
		exit(3);
	}
	else
	{
		cout << "Reading File" << endl;
		while (!infile.eof())
		{
			getline(infile, adding.name);
			for (int x = 0; x < 17; x++)
			{
				infile >> taking;
			}
			infile >> adding.matches;
			getline(infile, taking1);
			for (int x = 0; x < 17; x++)
			{
				infile >> taking;
			}
			infile >> adding.wins;
			for (int x = 0; x < 2; x++)
			{
				infile >> taking;
			}
			infile >> adding.losses;
			getline(infile, taking1);
			for (int x = 0; x < 20; x++)
			{
				infile >> taking;
			}
			infile >> adding.winPercent;
			getline(infile, taking1);
			getline(infile, taking1);
			Data.push_back(adding);
			hashdata.addItem(adding.name, adding.matches, adding.wins, adding.losses, adding.winPercent);
			count++;
		}

		cout << count << endl;
	}
}
void toBST(Hash &hashdata, BST &bstbyname, BST &bstbywins)
{

}
bool menu(Hash &hashdata, BST &bstbyname, BST &bstbywins, List<struct player> &Data)
{
	bool inloop = true;
	int choice = 0;
	cout << "Choose from one of the following by entering a number from the menu:" << endl;
	cout << "(1). Add new data" << endl;
	cout << "(2). Delete data" << endl;
	cout << "(3). Find and display one data record using the primary key" << endl;
	cout << "(4). List data in hash table sequence" << endl;
	cout << "(5). List data in key sequence(sorted)" << endl;
	cout << "(6). Print indented tree" << endl;
	cout << "(7). Efficiency" << endl;
	cout << "(8). <Team choice menu option>" << endl;
	cout << "(9). Quit" << endl;
	cin >> choice;

		switch (choice)
		{
		case 1:
		{
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			cout << "exiting program" << endl;
			inloop = false;
			break;
		}
		default:
		{
			cout << endl << endl << "*************************************************************" << endl
				<< "One of the menu items was not chosen. Please try again." << endl
				<< "*************************************************************" << endl << endl;
			break;
		}
		}
	
	return inloop;
}

void deletePlayerFromHash(Hash &hashdata)
{
	string name;
	hashdata.PrintTable();
	cout << "remove a player: ";
	cin >> name;
	hashdata.removePlayer(name);
	hashdata.PrintTable();
}
void findPlayerFromHash(Hash &hashdata)
{
	string name;
	hashdata.printEachName();
	cout << "search for a player: ";
	cin >> name;
	hashdata.FindPlayer(name);
}


void testBST(BST &tree1)
{
	tree1.breadth();
}

//******************************************************
// operator<<        
//******************************************************
template <class T>
std::ostream& operator<< (std::ostream &foo, List<T> *ListPtr)
{
	// Since operator<< is a friend of the List class, we can access
	// it's members directly.
	int itemCount = 0;
	if (ListPtr->empty()) cout << "List is empty" << endl;
	else
	{
		Node<T> *currPtr = ListPtr->getTail();
		while (currPtr != nullptr)
		{
			itemCount++;
			foo << itemCount << ". " << (currPtr->value) << endl;
			currPtr = currPtr->next;
		}
	}
	return foo;
}

