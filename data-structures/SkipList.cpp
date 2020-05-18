//
// created by Uladzislau Tumilovich
//

#include "SkipList.h"

// Function checks whether skiplist is empty or not
bool is_SkipListEmpty(SkipList skiplist)
{
    return skiplist.first == NULL || skiplist.first->next[0] == skiplist.last ? true : false;
}

// Function gives a random integer - 0 or 1
int randomiser()
{
    return rand() % 2;
}

// Function gives level for new node
int getSkipListNodeLevel(int maxLevel)
{
    int level = 1;
    while (level <= maxLevel && randomiser() < 0.5) level++;

    return level;
}

// Function creates new skiplist node 
SkipListNode *createSkipListNode(int value, int level)
{
    SkipListNode *newNode = new SkipListNode;

    newNode->value = value;
    newNode->next = new SkipListNode *[level];

    return newNode;
}

// Function finds node of given value
SkipListNode *findSkipListNode(SkipList skiplist, int value)
{
    SkipListNode *it = skiplist.first;
    for (int i = skiplist.maxLevel - 1; i >= 0; i--)
    {
        while (it->next[i]->value < value) it = it->next[i];
        if (it->next[i]->value == value) return it->next[i];
    }

    return NULL;
}

// Function inserts new node to a skiplist 
void insertSkipListNode(SkipList skiplist, int value)
{
    int level = getSkipListNodeLevel(skiplist.maxLevel);
    SkipListNode *newNode = createSkipListNode(value, level);

    SkipListNode *it = skiplist.first;
    for (int i = skiplist.maxLevel - 1; i >= 0; i--)
    {
        while (it->next[i]->value < value) it = it->next[i];
        if (i < level)
        {
            newNode->next[i] = it->next[i];
            it->next[i] = newNode;
        }
    }
}

// Function removes node of given value from skiplist
bool removeSkipListNode(SkipList skiplist, int value)
{
    SkipListNode *nodeToDelete = findSkipListNode(skiplist, value);
    if (nodeToDelete == NULL) return false;

    SkipListNode *previous[skiplist.maxLevel];
    SkipListNode *it = skiplist.first;

    for (int i = skiplist.maxLevel - 1; i >= 0; i--)
    {
        while (it->next[i]->value < nodeToDelete->value) it = it->next[i];
        previous[i] = it;
    }

    for (int i = skiplist.maxLevel - 1; i >= 0; i--)
    {
        if (previous[i]->next[i]->value == nodeToDelete->value)
        {
            previous[i]->next[i] = previous[i]->next[i]->next[i];
            nodeToDelete->next[i] = NULL;
        }
    }

    delete [] nodeToDelete->next;
    delete nodeToDelete;

    return true;
}

// Function creates new skiplist
SkipList createSkipList(int maxLevel)
{
    SkipListNode *firstNode = new SkipListNode;

    firstNode->value = -INFINITY;
    firstNode->next = new SkipListNode *[maxLevel];

    SkipListNode *lastNode = new SkipListNode;

    lastNode->value = INFINITY;
    lastNode->next = new SkipListNode *[maxLevel];

    for (int i = 0; i < maxLevel; i++)
    {
        firstNode->next[i] = lastNode;
        lastNode->next[i] = NULL;
    }

    SkipList skiplist;

    skiplist.maxLevel = maxLevel;
    skiplist.first = firstNode;
    skiplist.last = lastNode;
    
    return skiplist;
}

// Function gives an amount of elements of a given level
int SkipListSize(SkipList skiplist)
{
    if (is_SkipListEmpty(skiplist)) return 0;
    int count = 0;
    SkipListNode *it = skiplist.first->next[0];

    while (it->value != INFINITY)
    {
        count++;
        it = it->next[0];
    }

    return count;
}

// Function deletes skiplist
void deleteSkipList(SkipList &skiplist)
{
    SkipListNode *p = skiplist.first->next[0];
    SkipListNode *q = skiplist.first->next[0]->next[0];

    while (p->value != INFINITY)
    {
        delete [] p->next;
        delete p;
        p = q;
        q = q->next[0];
    }

    delete [] skiplist.first->next;
    delete [] skiplist.last->next;
    delete skiplist.first;
    delete skiplist.last;

    skiplist.first = NULL;
    skiplist.last = NULL;
}