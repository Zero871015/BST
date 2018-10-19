// Name: zero871015(B10615032)
// Date: 2018/10/17
// Last Update: 2018/10/19
// Problem statement: Binary search tree for test file

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		bool first = true;
		int temp;
		BinarySearchTree *T = NULL;
		//Insert n nodes.
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			if (T == NULL)
				T = new BinarySearchTree(temp);
			else
				T->Insert(temp);
		}
		//Post-order traversal.
		ShowPost(T, first);
		cout << endl;

		//Post-order traversal its mirror.
		BinarySearchTree *M = T->Mirror();
		first = true;
		ShowPost(M, first);
		cout << endl;

		//Insert a new number.
		cin >> temp;
		if (T == NULL)
			T = new BinarySearchTree(temp);
		else
			T->Insert(temp);

		//Pre-order traversal.
		first = true;
		ShowPre(T, first);
		cout << endl;

		//Show Height,Node,InternalNode,Max,Min.
		cout << Height(T) << endl;
		cout << Size(T) << endl;
		cout << InternalNode(T) << endl;
		cout << T->Max()->GetData() << endl;
		cout << T->Min()->GetData() << endl;

		//Two mirror to copy.
		M = T->Mirror();
		M = M->Mirror();

		//Two delete function.
		cin >> temp;
		Delete(M, temp, 0);
		first = true;
		ShowPre(M, first);
		cout << endl;
		first = true;
		M = T->Mirror();
		M = M->Mirror();
		Delete(M, temp, 1);
		ShowPre(M, first);
	}
	return 0;
}