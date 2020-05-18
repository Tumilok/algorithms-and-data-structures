//
// created by Uladzislau Tumilovich
//

#include "BST.h"

// Function finds node of given value in a tree
BSTNode *findBSTNode(BSTNode *root, int value)
{
	while (root != NULL)
	{
		if (root->value == value) return root;
		root = (root->value > value ? root->left : root->right);
	}

	return NULL;
}

// Function finds min node in a tree
BSTNode *findBSTMinNode(BSTNode *root)
{
	if (root == NULL) return NULL;
	while(root->left != NULL) root = root->left;
	return root;
}

// Function finds max node in a tree
BSTNode *findBSTMaxNode(BSTNode *root)
{
	if (root == NULL) return NULL;
	while(root->right != NULL) root = root->right;
	return root;
}

// Function finds predecessor node for given node
BSTNode *findPredecessorNode(BSTNode *node)
{
	if (node == NULL) return NULL;
	else if (node->left != NULL) return findBSTMaxNode(node->left);
	else
	{
		BSTNode *temp = node->parent;

		while(temp != NULL && temp->left == node)
		{
			node = temp;
			temp = node->parent;
		}

		return temp;
	}
}

// Function finds successor node for given node
BSTNode *findSuccessorNode(BSTNode *node)
{
	if (node == NULL) return NULL;
	else if (node->right != NULL) return findBSTMinNode(node->right);
	else
	{
		BSTNode *temp = node->parent;

		while(temp != NULL && temp->right == node)
		{
			node = temp;
			temp = node->parent;
		}

		return temp;
	}
}

// Function creates new node
BSTNode *createNode(int value)
{
	BSTNode *nodeToAdd = new BSTNode;

	nodeToAdd->left = nodeToAdd->right = nodeToAdd->parent = NULL;
	nodeToAdd->value = value;

	return nodeToAdd;
}

// Function inserts node of given value in a tree
void insertBSTNode(BSTNode *&root, int value)
{
	BSTNode *nodeToAdd = createNode(value);
	BSTNode *x = root;
	BSTNode *y = NULL;

	while (x != NULL)
	{
		y = x;
		if (value >= x->value) x = x->right;
		else x = x->left;
	}
	nodeToAdd->parent = y;

	if (nodeToAdd->parent == NULL) root = nodeToAdd;
	else
	{
		if (y->value <= nodeToAdd->value) y->right = nodeToAdd;
		else y->left = nodeToAdd;
	}
}

// Function removes node of given value from a tree
bool removeBSTNode(BSTNode *&root, int value)
{
	if (root == NULL) return false;

	BSTNode *nodeToRemove = findBSTNode(root, value);
	if (nodeToRemove == NULL) return false;

	BSTNode *x, *y;
	if(nodeToRemove->left == NULL || nodeToRemove->right == NULL) y = nodeToRemove;
	else y = findSuccessorNode(nodeToRemove);

	if(y->left != NULL) x = y->left;
	else x = y->right;

	if (x != NULL) x->parent = y->parent;

	if (y->parent == NULL) root = x;
	else if (y == y->parent->left) y->parent->left = x;
	else y->parent->right = x;
	if (y != nodeToRemove) nodeToRemove->value = y->value;

	delete y;

	return true;
}

// Function gives size of a tree
int BSTSize(BSTNode *root)
{
	if (root == NULL) return 0;
	else return 1 + BSTSize(root->left) + BSTSize(root->right);
}

// Function deletes whole tree
void deleteBST(BSTNode *&root)
{
	if (root == NULL) return;

	deleteBST(root->left);
	deleteBST(root->right);
	
	delete root;
	root = NULL;
}