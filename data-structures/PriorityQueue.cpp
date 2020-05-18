//
// created by Uladzislau Tumilovich
//

#include "PriorityQueue.h"

// Function checks whether heap is empty or not
bool isHeapEmpty(PriorityQueue *heap)
{
    return heap->currentSize == 0 ? true : false;
}

// Function gives index of the left child
int getLeftChild(int key)
{
    return key * 2 + 1;
}

// Function gives index of the right child
int getRightChild(int key)
{
    return key * 2 + 2;
}

// Function gives index of the parent
int getParent(int key) 
{
    return (key - 1) / 2;
}

// Function swaps two integers
void swap(int &a, int &b) 
{
    int tmp = a;
    a = b;
    b = tmp;
}

// Function creates a Heap
PriorityQueue *createHeap(int size)
{
    PriorityQueue *heap = new PriorityQueue;

    heap->maxSize = size;
    heap->currentSize = 0;
    heap->queueArray = new int[heap->maxSize];

    return heap;
}

// Function inserts element to a Heap
bool heapInsert(PriorityQueue *heap, int value)
{
    if (heap->currentSize == heap->maxSize) return false;
    heap->queueArray[heap->currentSize] = value;

    int key = heap->currentSize;

    while (key > 0 && heap->queueArray[getParent(key)] > heap->queueArray[key])
    {
        swap(heap->queueArray[getParent(key)], heap->queueArray[key]);
        key = getParent(key);
    }

    heap->currentSize++;

    return true;
}

// Function reorderes elements in a Heap
void heapify(PriorityQueue *heap, int key)
{
    int left = getLeftChild(key);
    int right = getRightChild(key);
    int min = key;

    if (left < heap->currentSize && heap->queueArray[left] < heap->queueArray[key]) min = left;  
    if (right < heap->currentSize && heap->queueArray[right] < heap->queueArray[min]) min = right; 

    if (min != key)
    {
        swap(heap->queueArray[key], heap->queueArray[min]);
        heapify(heap, min);
    }
}

// Function gives min element of a Heap
int heapExtract(PriorityQueue *heap)
{
    if(isHeapEmpty(heap)) return MAX;

    int min = heap->queueArray[0];
    heap->currentSize--;
    heap->queueArray[0] = heap->queueArray[heap->currentSize];
    heapify(heap, 0);

    return min;
}

// Function gives current size of a Heap
int heapSize(PriorityQueue *heap)
{
    return heap->currentSize;
}

// Function gives max size of a Heap
int heapMaxSize(PriorityQueue *heap)
{
    return heap->maxSize;
}

// Function frees memeory
void deleteHeap(PriorityQueue *heap)
{
    delete [] heap->queueArray;
    delete heap;
}
