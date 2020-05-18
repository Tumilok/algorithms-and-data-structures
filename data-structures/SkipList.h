//
// created by Uladzislau Tumilovich
//

#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <iostream>

#define INFINITY INT16_MAX

struct SkipListNode
{
    int value;
    SkipListNode **next;
};

struct SkipList
{
    SkipListNode *first;
    SkipListNode *last;
    int maxLevel;
};

bool is_SkipListEmpty(SkipList skiplist);
int randomiser();
int getSkipListNodeLevel(int maxLevel);
SkipListNode *createSkipListNode(int value, int level);
SkipListNode *findSkipListNode(SkipList skiplist, int value);
void insertSkipListNode(SkipList skiplist, int value);
bool removeSkipListNode(SkipList skiplist, int value);
SkipList createSkipList(int maxLevel);
int SkipListSize(SkipList skiplist);
void deleteSkipList(SkipList &skiplist);

#endif //SKIPLIST_H