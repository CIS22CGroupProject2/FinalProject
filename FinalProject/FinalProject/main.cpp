#include <iostream>
#include <fstream>
#include <string>
#include "BST.hpp"
#include "LinkedList.h"

using namespace std;
void BinaryTest();
void fileInput(List<struct player> &Data);

int main()
{
	List<struct player> Data;
	{

	};
	fileInput(Data);

	
	system("pause");
}

void fileInput(List<struct player> &Data)
{
	ifstream infile;
	player adding;
	char taking;
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
			for (int x = 0; x < 15; x++)
			{
				infile >> taking;
				cout << taking;
				cout << x;
			}
		}
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