#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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

//File Input/Output
void fileInput(List<struct player> &Data, Hash &hashdata);
void fileExport(List<struct player> &Data);
//Data transfer
void toBST(List<struct player> &Data, BST &bstbyname, BST &bstbywins);
//Test Function
void testBST(BST&);
//Selection UI
bool menu(Hash &hashdata, BST &bstbyname, BST &bstbywins, List<struct player> &Data);
//Adding Data
void addData(Hash &hashdata, BST &bstbyname, BST &bstbywins, List<struct player> &Data);
//Removing Data
void removeData(Hash &hashdata, BST &bstbyname, BST &bstbywins, List<struct player> &Data);
//Display One Data Point
void hashFindName(Hash &hashdata);
//Display Hash Map
void hashPrint(Hash &hashdata);
//Display Sorted Data with BST
void BSTPrint(BST &bstbyname, BST &bstbywins);
//Display BST Tree with Indentations
void BSTIndent(BST &bstbyname, BST &bstbywins);
//Display Efficiency

std::ostream& operator<< (std::ostream &foo, player value)
{
	foo << left << setw(20) << value.name << " Wins: " << setw(4) << value.wins << " Losses: " << setw(4) << value.losses << " Matches: " << setw(4) << value.matches << " Win Percentage: " << setw(4) << value.winPercent << "%";
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
	toBST(Data, bstbyname, bstbywins);
	cout << "Printing list of players inputted" << endl << &Data;
	while (inloop == true)
	{
		inloop = menu(hashdata, bstbyname, bstbywins, Data);
	}
	fileExport(Data);
	
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
		cout << "Reading File...." << endl << endl;
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

		cout << endl << count << " items were found in the file..." << endl << endl;
		system("pause");
	}
}

void fileExport(List<struct player> &Data)
{
	ofstream outfile;

	outfile.open("players.txt");
	if (!outfile)
	{
		cerr << "Open Failed";
		exit(3);
	}
}

void toBST(List<struct player> &Data, BST &bstbyname, BST &bstbywins)
{
	Node<struct player> *currPtr = Data.getTail();
	while (currPtr != nullptr)
	{
		bstbyname.appendByName(currPtr->value.name, currPtr->value.matches, currPtr->value.wins, currPtr->value.losses, currPtr->value.winPercent);
		bstbyname.appendByWins(currPtr->value.name, currPtr->value.matches, currPtr->value.wins, currPtr->value.losses, currPtr->value.winPercent);
		currPtr = currPtr->next;
	}
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
	cout << "(5). List data in key sequence(sorted) by name" << endl;
	cout << "(6). Print indented tree" << endl;
	cout << "(7). Efficiency" << endl;
	cout << "(8). <Team choice menu option>" << endl;
	cout << "(9). Quit" << endl;
	cin >> choice;
	if (choice < 1 || choice > 9)
	{
		cout << endl << endl 
			<< "*************************************************************" << endl
			<< "One of the menu items was not chosen. Please try again." << endl
			<< "*************************************************************" << endl 
			<< endl;
	}
	else
	{
		if (choice == 1)
		{
			
		}
		else if (choice == 2)
		{

		}
		else if (choice == 3)
		{
			hashFindName(hashdata);
		}
		else if (choice == 4)
		{

		}
		else if (choice == 5)
		{

		}
		else if (choice == 6)
		{

		}
		else if (choice == 7)
		{

		}
		else if (choice == 8)
		{

		}
		else if (choice == 9)
		{
			inloop = false;
		}
	}
	return inloop;
}

void addData(Hash &hashdata, BST &bstbyname, BST &bstbywins, List<struct player> &Data)
{
	player adding;
	int choice = 0;
	string name;
	int wins, losses, winpercent, matches;
	cout << "Choose one of the following options: " << endl
		<< "(1). Add Data by Matches/Win Percentage" << endl
		<< "(2). Add Data by Wins/Losses" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "Enter the name of the player: ";
		cin >> name;
		cout << "Enter the number of matches played: ";
		cin >> matches;
		cout << "Enter the win percentage of the player: ";
		cin >> winpercent;
		wins = winpercent * matches * 0.01;
		losses = matches - wins;
		hashdata.addItem(name, matches, wins, losses, winpercent);
		bstbyname.appendByName(name, matches, wins, losses, winpercent);
		bstbywins.appendByName(name, matches, wins, losses, winpercent);
		adding.name = name;
		adding.matches = matches;
		adding.wins = wins;
		adding.losses = losses;
		adding.winPercent = winpercent;
		Data.push_back(adding);
	}
	else if (choice == 2)
	{
		cout << "Enter the name of the player: ";
		cin >> name;
		cout << "Enter the number of wins: ";
		cin >> wins;
		cout << "Enter the number of losses: ";
		cin >> losses;
		matches = wins + losses;
		winpercent = (wins * 100) / matches;
		hashdata.addItem(name, matches, wins, losses, winpercent);
		bstbyname.appendByName(name, matches, wins, losses, winpercent);
		bstbywins.appendByName(name, matches, wins, losses, winpercent);
		adding.name = name;
		adding.matches = matches;
		adding.wins = wins;
		adding.losses = losses;
		adding.winPercent = winpercent;
		Data.push_back(adding);
	}
	else
	{
		cout << "Invalid Choice Entered. Please Try Again" << endl << endl;
	}
}

void removeData(Hash &hashdata, BST &bstbyname, BST &bstbywins, List<struct player> &Data)
{

}

void hashFindName(Hash &hashdata)
{
	string name;
	int index;
	cout << "Enter the name of the player you are trying to find: ";
	cin >> name;
	index = hashdata.hash(name);
	hashdata.FindPlayer(index, name);
}

void hashPrint(Hash &hashdata)
{

}

void BSTPrint(BST &bstbyname, BST &bstbywins)
{

}

void BSTIndent(BST &bstbyname, BST &bstbywins)
{

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
			foo << itemCount << ". ";
			if (itemCount < 10)
			{
				foo << " ";
			}
			foo << (currPtr->value) << endl;
			currPtr = currPtr->next;
		}
	}
	return foo;
}

