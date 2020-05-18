//
// created by Uladzislau Tumilovich
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

struct Node
{
    int value;
    Node *next, *previous;
};

Node *createDoublyLinkedListNode(int value);
bool isDoublyLinkedListEmpty(Node *head);
void pushDoublyLinkedListNode(Node *&head, int value);
void appendDoublyLinkedListNode(Node *&head, int value);
bool insertDoublyLinkedListNodeBefore(Node *&head, Node *nextNode, int value);
bool insertDoublyLinkedListNodeAfter(Node *previousNode, int value);
Node *findDoublyLinkedListNode(Node *head, int value);
bool removeDoublyLinkedListNode(Node *&head, int value);
int doublyLinkedListSize(Node *head);
void deleteDoublyLinkedList(Node *&head);

#endif //DOUBLY_LINKED_LIST_H