//
// Created by Uladzislau Tumilovich
//

#ifndef GRAPHS_UTILS_H
#define GRAPHS_UTILS_H

#include <iostream>
#include <stack>

#define WHITE 0
#define GREY 1
#define BLACK 2
#define INF INT16_MAX

struct vertex
{
    int value;
    vertex *next;
};

struct Data
{
    int value;
    int priority;
};

struct PriorityQueue
{

    int maxSize;
    int currentSize;
    Data *queueArray;
};

void printStack(std::stack<int> stack);

vertex **createDirectedListGraph(int v, int e);
vertex **createUndirectedListGraph(int v, int e);
void printListGraph(vertex **G, int v);
void deleteListGraph(vertex **G, int v);

int **createDirectedMatrixGraph(int v, int e);
int **createUndirectedMatrixGraph(int v, int e);
int **createWeightedDirectedMatrixGraph(int v, int e);
int **createWeightedUndirectedMatrixGraph(int v, int e);
void printMatrixGraph(int **G, int v);
void deleteMatrixGraph(int **G, int v);

int getLeftChild(int key);
int getRightChild(int key);
int getParent(int key);
void swapData(Data &a, Data &b);
bool empty(PriorityQueue *heap);
PriorityQueue *createHeap(int size);
bool heapInsertData(PriorityQueue *heap, int value, int priority);
void heapify(PriorityQueue *heap, int key);
Data heapExtractData(PriorityQueue *heap);
void deleteHeap(PriorityQueue *heap);

#endif //GRAPHS_UTILS_H
