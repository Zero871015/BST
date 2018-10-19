//////////////////////////////////
//Name: Zero871015
//Date: 4/19/2018
//Todo: Class of Binary Tree
//////////////////////////////////

#include "BinaryNode.h"

//defualt constructor
Node::Node()
{
	this->leftNode = NULL;
	this->rightNode = NULL;
	this->value = 0;
	this->isSet = false;
}

//constructor
Node::Node(int num)
{
	this->leftNode = NULL;
	this->rightNode = NULL;
	this->value = num;
	this->isSet = true;
}

//destructor
Node::~Node()
{
}

//add new number to this tree
void Node::add(int num)
{
	if (this->isSet == false)
	{
		this->value = num;
		this->isSet = true;
	}
	else
	{
		if (this->value > num)
		{
			if (this->leftNode)
			{
				this->leftNode->add(num);
			}
			else
			{
				Node *temp = new Node(num);
				this->leftNode = temp;
			}
		}
		else
		{
			if (this->rightNode)
			{
				this->rightNode->add(num);
			}
			else
			{
				Node *temp = new Node(num);
				this->rightNode = temp;
			}
		}
	}
}

//sort and show numbers of this tree
void Node::show()
{
	if(this->leftNode)
		this->leftNode->show();
	cout << this->value << " ";
	if(this->rightNode)
		this->rightNode->show();
}