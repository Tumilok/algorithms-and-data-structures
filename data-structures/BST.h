//
// created by Uladzislau Tumilovich
//

#ifndef BST_H
#define BST_H

#include <iostream>

struct BSTNode
{
	int value;
	BSTNode *left, *right, *parent;
};

BSTNode *findBSTNode(BSTNode *root, int value);
BSTNode *findBSTMinNode(BSTNode *root);
BSTNode *findBSTMaxNode(BSTNode *root);
BSTNode *findPredecessorNode(BSTNode *node);
BSTNode *findSuccessorNode(BSTNode *node);
BSTNode *createBSTNode(int value);
void insertBSTNode(BSTNode *&root, int value);
bool removeBSTNode(BSTNode *&root, int value);
int BSTSize(BSTNode *root);
void deleteBST(BSTNode *&root);

#endif //BST_H