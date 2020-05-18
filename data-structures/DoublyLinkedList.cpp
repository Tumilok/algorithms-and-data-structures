//
// created by Uladzislau Tumilovich
//

#include "DoublyLinkedList.h"

// Function creates new Node
Node *createDoublyLinkedListNode(int value)
{
    Node *newNode = new Node;

    newNode->value = value;
    newNode->next = newNode->previous = NULL;

    return newNode;
}

// Function shows whether List is empty or not
bool isDoublyLinkedListEmpty(Node *head)
{
    return head == NULL ? true : false;
}

// Function adds node at the front of the List
void pushDoublyLinkedListNode(Node *&head, int value)
{
    Node *newNode = createDoublyLinkedListNode(value);

    if (isDoublyLinkedListEmpty(head)) head = newNode;
    else
    {
        head->previous = newNode;
        newNode->next = head;

        head = newNode;
    }
}

// Function adds node at the end of the List
void appendDoublyLinkedListNode(Node *&head, int value)
{
    Node *newNode = createDoublyLinkedListNode(value);

    if (isDoublyLinkedListEmpty(head)) head = newNode;
    else
    {
        Node *p = head;
        while (p->next != NULL) p = p->next;

        p->next = newNode;
        newNode->previous = p;
    }
}

// Function adds node before the given node of the List
bool insertDoublyLinkedListNodeBefore(Node *&head, Node *nextNode, int value)
{   
    if (nextNode == NULL) return false;
    else if (nextNode->previous == NULL)
    {
        pushDoublyLinkedListNode(head, value);
        return true;
    }
    else
    {    
        Node *newNode = createDoublyLinkedListNode(value);

        newNode->previous = nextNode->previous;
        nextNode->previous = newNode;
        newNode->next = nextNode;
        newNode->previous->next = newNode;

        return true;
    }
}

// Function adds node after the given node of the List
bool insertDoublyLinkedListNodeAfter(Node *previousNode, int value)
{
    if (previousNode == NULL) return false;

    Node *newNode = createDoublyLinkedListNode(value);
    
    newNode->next = previousNode->next;
    previousNode->next = newNode;
    newNode->previous = previousNode;
    if (newNode->next != NULL) newNode->next->previous = newNode;

    return true;
}

// Function finds and returns the node
Node *findDoublyLinkedListNode(Node *head, int value)
{
    while (head != NULL)
    {
        if (head->value == value) return head;
        head = head->next;
    }

    return NULL;
}

// Function removes the node from the List
bool removeDoublyLinkedListNode(Node *&head, int value)
{
    if (isDoublyLinkedListEmpty(head)) return false;

    Node *nodeToDelete = findDoublyLinkedListNode(head, value);

    if (nodeToDelete == NULL) return false;

    if (nodeToDelete->previous == NULL && nodeToDelete->next == NULL)
    {
        delete nodeToDelete;
        head = NULL;

        return true;
    }
    else if (nodeToDelete->previous == NULL)
    {
        head = head->next;
        head->previous = NULL;
        delete nodeToDelete;

        return true;
    }
    else if (nodeToDelete->next == NULL)
    {
        nodeToDelete->previous->next = NULL;
        delete nodeToDelete;

        return true;
    }
    else
    {
        nodeToDelete->previous->next = nodeToDelete->next;
        nodeToDelete->next->previous = nodeToDelete->previous;
        delete nodeToDelete;

        return true;
    }
}

// Function gives size of the List
int doublyLinkedListSize(Node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    
    return count;
}

// Function deletes Doubly Linked List
void deleteDoublyLinkedList(Node *&head)
{
    Node *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        delete head;
        head = next;
    }
}
