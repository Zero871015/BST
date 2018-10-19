// Name: zero871015(B10615032)
// Date: 2018/10/17
// Last Update: 2018/10/19
// Problem statement: Binary search tree class file

#pragma once
#include <iostream>
using namespace std;

class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(int);
	~BinarySearchTree();
	void Insert(int);
	friend void Delete(BinarySearchTree*&, int, int);
	BinarySearchTree* Max();
	BinarySearchTree* Min();
	friend int InternalNode(BinarySearchTree*);
	friend int Size(BinarySearchTree*);
	friend int Height(BinarySearchTree*);
	friend void ShowPost(BinarySearchTree*, bool&);
	friend void ShowPre(BinarySearchTree*, bool&);
	BinarySearchTree* Mirror();
	int GetData();
private:
	int data;
	BinarySearchTree *left, *right;
};

