#include <iostream>
#include <fstream>
#include <string>
#include "BST.hpp"
#include "LinkedList.h"
#include "Hash.h"

using namespace std;
//void BinaryTest();
void fileInput(List<struct player> &Data, Hash &hashdata);
void deletePlayerFromHash(Hash&);
void findPlayerFromHash(Hash&);

//add, delete and modify entries in BST and Hashtable
string playername;         //input variables for user
int m, w, l, winp;         //matches, wins, losses, win%
/*
void addEntry(BST<T> BStree, Hash hashdata){
	cout << "Enter a new player to add" << endl;
	cin >> playername;

	cout << "Enter number of matches, wins , losses, and winning percentage" << endl;
	cin >> m >> w >> l >> winp;
	if(cin.fail()){
		cin.clear();
	}
	//from Struct Player in LInkedListNode.h
	player p;
	p->name = playername;
  p->matches = m;
	p->wins = w;
	p->losses = l;
	p->winPercent = winp;

	//add entry to BST
	BStree.append(p);

	//add entry to hashtable and print all entries
	hashdata.addItem(playername, m, w, l, winp);
	hashdata.PrintTable();

}


//delete entry from BST and hashtable
void deleteEntry(BST<T> BStree, Hash hashdata){
	string pname;
	 cout << "Enter a player name to delete from the list" << endl;
	 cin >> pname;

	bool playerfound = hashdata.FindPlayer(pname);
	if(playerfound){
	//delete player entry from hashtable
	}
  //if player entry is in the BST, remove the entry
	if(BStree.Search(pname)){
		BStree.remove(pname);
	}
	else{
		cout << pname << "was not found in the BST" << endl;
	}

}


void modifyEntry(BST<T> BStree, Hash hashdata);

*/


int main()
{
	List<struct player> Data;
	Hash hashdata;
	fileInput(Data, hashdata);
	deletePlayerFromHash(hashdata);
	findPlayerFromHash(hashdata);
	
	system("pause");
}

void fileInput(List<struct player> &Data, Hash &hashdata)
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
			hashdata.addItem(adding.name, adding.matches, adding.wins, adding.losses, adding.winPercent);
			count++;
		}

		cout << count << endl;
	}
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



