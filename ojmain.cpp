// Name: zero871015(B10615032)
// Date: 2018/10/17
// Last Update: 2018/10/19
// Problem statement: Binary search tree (online judge version)

#include <iostream>
using namespace std;

struct BinarySearchTree
{
	int data;
	BinarySearchTree* left;
	BinarySearchTree* right;
};

int GetSize(BinarySearchTree *t)
{
	if (t == NULL)return 0;
	return GetSize(t->left) + GetSize(t->right) + 1;
}

void Insert(BinarySearchTree *&t,int n)
{
	if (t == NULL)
	{
		t = new BinarySearchTree;
		t->data = n;
		t->left = NULL;
		t->right = NULL;
	}
	else
	{
		if (n < t->data)
			Insert(t->left, n);
		else
			Insert(t->right, n);
	}
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

void ShowPostM(BinarySearchTree* node, bool &first)
{
	if (node == NULL)return;
	ShowPostM(node->right, first);
	ShowPostM(node->left, first);
	if (!first) cout << " ";
	else first = false;
	cout << node->data;
}

void ShowPreM(BinarySearchTree *node, bool &first)
{
	if (node == NULL)return;
	if (!first) cout << " ";
	else first = false;
	cout << node->data;
	ShowPreM(node->right, first);
	ShowPreM(node->left, first);
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

int InternalNode(BinarySearchTree* node)
{
	if (node == NULL)return 0;
	if (node->left != NULL || node->right != NULL)
		return InternalNode(node->left) + InternalNode(node->right) + 1;
	return 0;
}


BinarySearchTree* Max(BinarySearchTree* t)
{
	if (t->right == NULL) return t;
	return Max(t->right);
}

BinarySearchTree* Min(BinarySearchTree* t)
{
	if (t->left == NULL) return t;
	return Min(t->left);
}

void Delete(BinarySearchTree *&node, int n, int mode)
{
	if (node == NULL) cout << "Not Found" << endl;
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
		else if (node->left&&node->right)
		{
			if (mode == 0)
			{
				BinarySearchTree *temp = Max(node->left);
				node->data = temp->data;
				Delete(node->left, temp->data, 0);
			}
			else
			{
				BinarySearchTree *temp = Min(node->right);
				node->data = temp->data;
				Delete(node->right, temp->data, 1);
			}
		}
		else
		{
			if (node->left == NULL && node->right == NULL)
				node = NULL;
			else if (node->left != NULL)
				node = node->left;
			else
				node = node->right;
		}
	}
}

void Copy(BinarySearchTree *t, BinarySearchTree *&t2)
{
	if (t == NULL)t2 = NULL;
	else
	{
		t2 = new BinarySearchTree;
		t2->data = t->data;
		Copy(t->left, t2->left);
		Copy(t->right, t2->right);
	}
}

int main()
{
	int n;
	cin >> n;
	bool first = true;
	int temp;
	BinarySearchTree *T = NULL;
	//Insert n nodes.
	while (GetSize(T) != n)
	{
		cin >> temp;
		Insert(T, temp);
	}
	//Post-order traversal.
	ShowPost(T, first);
	cout << endl;

	//Post-order traversal its mirror.
	first = true;
	ShowPostM(T, first);
	cout << endl;

	//Insert a new number.
	cin >> temp;
	Insert(T, temp);

	//Pre-order traversal.
	first = true;
	ShowPre(T, first);
	cout << endl;

	//Show Height,Node,InternalNode,Max,Min.
	cout << Height(T) << endl;
	cout << GetSize(T) << endl;
	cout << InternalNode(T) << endl;
	cout << Max(T)->data << endl;
	cout << Min(T)->data << endl;

	//Copy a new tree.
	BinarySearchTree *T2 = NULL;
	Copy(T, T2);

	//Two delete function.
	cin >> temp;
	Delete(T, temp, 0);
	first = true;
	ShowPre(T, first);
	cout << endl;
	first = true;
	Delete(T2, temp, 1);
	ShowPre(T2, first);
	return 0;
}