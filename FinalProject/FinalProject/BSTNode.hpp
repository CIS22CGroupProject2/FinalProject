#pragma once
#ifndef BSTNODE_H
#define BSTNODE_H
//**************************
// Node for BST 
//**************************

#include <string>
#include <iostream>
#include "LinkedList.h"

class BSTNode
{
private:
	// data in node for BST
	std::string name;
	int matches, wins, losses, winPercent;
	BSTNode *left;
	BSTNode *right;

public:
	//default constructor
	BSTNode() {}
	//constructor
	BSTNode(std::string n, int m, int w, int l, int wp) 
	{
		name = n;
		matches = m;
		wins = w;
		losses = l;
		winPercent = wp;

		left = nullptr;
		right = nullptr; 
	}
	
	// setters
	void setName(std::string n) { name = n; }
	void setMatches(int m) { matches = m; }
	void setWins(int w) { wins = w; }
	void setLosses(int l) { losses = l; }
	void setWinPercent(int wp) { winPercent = wp; }

	//getters
	std::string getName() { return name; }
	int getMatches() { return matches; }
	int getWins() { return wins; }
	int getLosses() { return losses; }
	int getWinPercent() { return winPercent; }


	//get and setters for left child
	void setLeft(BSTNode *l) { left = l; }
	BSTNode *getLeft() { return left; }

	//getters and setters for right child
	void setRight(BSTNode *r) { right = r; }
	BSTNode *getRight() { return right; }


	//destructor
	virtual ~BSTNode() {}
};
#endif