#pragma once
#include <iostream>
#include <memory>

using namespace std;

class BST
{
	struct Node
	{
		int key;
		shared_ptr<Node> left_children;
		shared_ptr<Node> right_children;
		weak_ptr<Node>   parent;
	};
	shared_ptr<Node> root;
	

public:
	BST();
	bool find(int value);
	void insertNode(shared_ptr<Node> &parent, shared_ptr<Node> &currNode, int value);
	void insert(int value);
	shared_ptr<Node>& minValue(std::shared_ptr<Node>& node) 
	{
		shared_ptr<Node> currNode = node;
		while (currNode && currNode->left_children != nullptr)
		{
			currNode = currNode->left_children;
		}
		node = currNode;
		return node;
	};
	void eraseNode(shared_ptr<Node>& currNode, int value);
	void erase(int value);
	~BST();
};

BST::BST()
{
	root = nullptr;
}

bool BST::find(int value)
{	
	shared_ptr<Node> currNode = root;

	while (currNode)
	{
		if (currNode->key == value)
			return true;
		
		else if (currNode->key > value)
			currNode = currNode->left_children;
		
		else
			currNode = currNode->right_children;
	}

	return false;
}

void BST::insertNode(shared_ptr<Node>& parent, shared_ptr<Node>& currNode, int value)
{
	if (currNode==nullptr)
	{
		currNode = make_shared<Node>();
		currNode->key = value;
		currNode->left_children = nullptr;
		currNode->right_children = nullptr;
		currNode->parent = parent;
		return;
	}

	if (value > currNode->key)
		insertNode(currNode, currNode->right_children, value);
	else
		insertNode(currNode, currNode->left_children, value);
}

void BST::insert(int value)
{
	if (root == nullptr)
	{
		root = make_shared<Node>();
		root->key = value;
		root->left_children  = nullptr;
		root->right_children = nullptr;
		root->parent.lock()  = nullptr;
		return;
	}
	else
	{
		insertNode(root, root, value);
	}
}

void BST::eraseNode(shared_ptr<Node>& currNode, int value)
{
	if (currNode == nullptr)
		return;

	else
	{
		if (value > currNode->key)
			eraseNode(currNode->right_children, value);
		else if(value < currNode->key)
			eraseNode(currNode->left_children, value);

		else
		{
			if (currNode->left_children == nullptr)
				currNode = currNode->right_children;
			else if(currNode->right_children == nullptr)
				currNode = currNode->left_children;
			else
			{
				shared_ptr<Node> tmp = minValue(currNode->right_children);
				currNode->key = tmp->key;
				currNode->parent = tmp->parent;
			}
		}
	}

}

void BST::erase(int value)
{
	eraseNode(root, value);
}


BST::~BST()
{
}
