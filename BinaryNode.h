//Name: Zero871015
//Date: 4/19/2018
//Todo: Class of Binary Tree

#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	Node();			//defualt constructor
	Node(int);		//constructor
	~Node();		//destructor
	void add(int);	//add new number to this tree
	void show();	//sort and show numbers of this tree

private:
	int value;			//this node's value
	Node* leftNode;		//pointer to left node, number will smaller than this node
	Node* rightNode;	//pointer to right node, number will larger than this node
	bool isSet = false;	//value of this node is setted
};