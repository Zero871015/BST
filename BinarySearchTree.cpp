// Name: zero871015(B10615032)
// Date: 2018/10/17
// Last Update: 2018/10/19
// Problem statement: Binary search tree class file

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	this->data = 0;
	this->left = NULL;
	this->right = NULL;
}

BinarySearchTree::BinarySearchTree(int n)
{
	this->data = n;
	this->left = NULL;
	this->right = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
}

void BinarySearchTree::Insert(int n)
{
	if (n > this->data)
	{
		if (this->right == NULL)
		{
			BinarySearchTree *temp = new BinarySearchTree(n);
			temp->left = NULL;
			temp->right = NULL;
			this->right = temp;
		}
		else
		{
			this->right->Insert(n);
		}
	}
	else if (n < this->data)
	{
		if (this->left == NULL)
		{
			BinarySearchTree *temp = new BinarySearchTree(n);
			temp->left = NULL;
			temp->right = NULL;
			this->left = temp;
		}
		else
		{
			this->left->Insert(n);
		}
	}
}

BinarySearchTree* BinarySearchTree::Max()
{
	if (this->right == NULL) return this;
	return this->right->Max();
}

BinarySearchTree* BinarySearchTree::Min()
{
	if (this->left == NULL) return this;
	return this->left->Min();
}

BinarySearchTree * BinarySearchTree::Mirror()
{
	if (this == NULL)
		return NULL;
	BinarySearchTree *M = new BinarySearchTree(this->data);
	M->left = this->right->Mirror();
	M->right = this->left->Mirror();
	return M;
}

int BinarySearchTree::GetData()
{
	return this->data;
}


int InternalNode(BinarySearchTree* node)
{
	if (node == NULL)return 0;
	if (node->left != NULL || node->right != NULL)
		return InternalNode(node->left) + InternalNode(node->right) + 1;
	return 0;
}

int Size(BinarySearchTree* node)
{
	if (node == NULL)return 0;
	return Size(node->left) + Size(node->right) + 1;
}

int Height(BinarySearchTree* node)
{
	if (node == NULL)return 0;
	int L = Height(node->left);
	int R = Height(node->right);
	if (L > R)
		return L + 1;
	else
		return R + 1;
}

void ShowPost(BinarySearchTree* node, bool &first)
{
	if (node == NULL)return;
	ShowPost(node->left, first);
	ShowPost(node->right, first);
	if (!first) cout << " ";
	else first = false;
	cout << node->data;
}

void ShowPre(BinarySearchTree *node, bool &first)
{
	if (node == NULL)return;
	if (!first) cout << " ";
	else first = false;
	cout << node->data;
	ShowPre(node->left, first);
	ShowPre(node->right, first);
}

void Delete(BinarySearchTree *&node, int n, int mode)
{
	if (&node == NULL) cout << "Not Found" << endl;
	else if (n < node->data)
	{
		Delete(node->left, n, mode);
	}
	else if (n > node->data)
	{
		Delete(node->right, n, mode);
	}
	else
	{
		if (node->left == NULL && node->right == NULL)node = NULL;
		else if (node->left == NULL)
		{
			node = node->right;
		}
		else if (node->right == NULL)
		{
			node = node->left;
		}
		else
		{
			if (mode == 0)
			{
				BinarySearchTree* temp = node->left->Max();
				node->data = temp->data;
				Delete(node->left, temp->data, 0);
			}
			else
			{
				BinarySearchTree* temp = node->right->Min();
				node->data = temp->data;
				Delete(node->right, temp->data, 1);
			}
		}
	}
}
