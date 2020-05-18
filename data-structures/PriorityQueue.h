//
// created by Uladzislau Tumilovich
//

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

#define MAX INT16_MAX

struct PriorityQueue
{
    int maxSize;        
    int currentSize;    
    int *queueArray;    
};

bool isHeapEmpty(PriorityQueue *heap);
int getLeftChild(int key);
int getRightChild(int key);
int getParent(int key) ;
void swap(int &a, int &b) ;
PriorityQueue *createHeap(int size);
bool heapInsert(PriorityQueue *heap, int value);
void heapify(PriorityQueue *heap, int key);
int heapExtract(PriorityQueue *heap);
int heapSize(PriorityQueue *heap);
int heapMaxSize(PriorityQueue *heap);
void deleteHeap(PriorityQueue *heap);

#endif //PRIORITY_QUEUE_H