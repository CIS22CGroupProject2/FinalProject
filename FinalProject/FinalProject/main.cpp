#include <iostream>
#include <fstream>
#include <string>
#include "BST.hpp"
#include "LinkedList.h"
#include "Hash.h"

using namespace std;
void BinaryTest();
void fileInput(List<struct player> &Data, Hash hashdata);

int main()
{
	List<struct player> Data;
	Hash hashdata;
	fileInput(Data, hashdata);

	
	system("pause");
}

void fileInput(List<struct player> &Data, Hash hashdata)
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
		
		cout << count;
	}
}


void BinaryTest()
{
	BST<int> tree;

	tree.addNode(3);
	tree.addNode(1);
	tree.addNode(6);
	tree.addNode(4);

	if (tree.isEmpty())
	{
		cout << "Is empty";
	}
	else
		cout << "not empty";

	tree.breadth();

}