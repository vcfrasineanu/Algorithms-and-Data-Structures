/**
 *  Task: Class for representing a binary search tree + solutions for 
 *  several problems
 */ 

// -----------------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>

using namespace std;

// -----------------------------------------------------------------------------

struct Node
{
	int data;
	Node* left;
	Node* right;
};

class BST
{
public:
	BST();

	~BST();

	void addNode( int newData );

	Node* getRoot();

	int getDepth();

private:
	Node* root;
};

BST::BST()
{
	root = new Node;
	root = NULL;
}

BST::~BST()
{
}

void BST::addNode( int newData )
{
	Node* newNode = new Node;
	newNode->data = newData;
	newNode->left = NULL;
	newNode->right = NULL;

	if ( root == NULL )
	{
		root = newNode;
	}
	else
	{
		Node* it = root;
		while ( it != NULL )
		{
			if (it->data >= newData)
			{
				if (it->left == NULL) 
				{
					it->left = newNode;
					break;
				}
				it = it->left;
			}
			else
			{
				if (it->right == NULL)
				{
					it->right = newNode;
					break;
				}
				it = it->right;
			}
		}
	}
}

Node* BST::getRoot()
{
	return root;
}

void printInOrder( Node* root )
{
	if (root != NULL)
	{
		printInOrder(root->left);
		cout << root->data << " ";
		printInOrder(root->right);
	}
}

int getDepthRoot( Node* root )
{
	if (root->left == NULL && root->right == NULL)
	{
		return 0;
	}
	else
	{
		if ( root->left != NULL && root->right != NULL)
		{
			int leftSubTree = getDepthRoot(root->left)+1;
			int rightSubTree = getDepthRoot(root->right)+1;

			if ( leftSubTree<rightSubTree )
			{
				return rightSubTree;
			}
			else
			{
				return leftSubTree;
			}
		}
		if ( root->left != NULL ) return getDepthRoot(root->left)+1;
		if ( root->right != NULL ) return getDepthRoot(root->right)+1;
	}
}

int BST::getDepth()
{
	return getDepthRoot( root );
}

bool checkBalanced( Node* root )
{
	if ( root == NULL ) return true;
	if ( root->left == NULL )
	{
		if ( root->right == NULL ) return true;
		if ( root->right->right == NULL && root->right->left == NULL ) return true;
		return false;
	}
	if ( root->right == NULL )
	{
		if ( root->left == NULL ) return true;
		if ( root->left->right == NULL && root->left->left == NULL ) return true;
		return false;
	}

	if ( abs(getDepthRoot(root->left) - getDepthRoot(root->right)) == 1 || 
		 abs(getDepthRoot(root->left) - getDepthRoot(root->right)) == 0 )	
		return checkBalanced( root->left ) && checkBalanced( root->right );
	else
		return false;
}

int main()
{
	BST test;

    test.addNode(5);
    test.addNode(1);
    test.addNode(4);
    test.addNode(4);
    test.addNode(5);
    test.addNode(9);
    test.addNode(7);
    test.addNode(13);
    test.addNode(0);
    //test.addNode(3);

   	printInOrder( test.getRoot() );
   	cout << endl;

   	cout << test.getDepth() << endl;

   	cout << checkBalanced(test.getRoot()) << endl;

	return 0;
}
