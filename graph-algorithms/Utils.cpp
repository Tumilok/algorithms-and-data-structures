//
// created by Uladzislau Tumilovich
//

#include "Utils.h"

void printStack(std::stack<int> stack)
{
    while (!stack.empty())
    {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

// GRAPH UTILS

vertex **createDirectedListGraph(int v, int e)
{
    vertex **G = new vertex *[v];
    for (int i = 0; i < v; i++) G[i] = NULL;

    int firstValue, secondValue;

    for(int i = 0; i < e; i++)
    {
        std::cin >> firstValue >> secondValue;

        vertex *newVertex = new vertex;
        newVertex->value = secondValue;
        newVertex->next = G[firstValue];
        G[firstValue] = newVertex;
    }

    return G;
}

vertex **createUndirectedListGraph(int v, int e)
{
    vertex **G = new vertex *[v];
    for (int i = 0; i < v; i++) G[i] = NULL;

    int firstValue, secondValue;

    for(int i = 0; i < e; i++)
    {
        std::cin >> firstValue >> secondValue;

        vertex *firstNewVertex = new vertex;
        firstNewVertex->value = secondValue;
        firstNewVertex->next = G[firstValue];
        G[firstValue] = firstNewVertex;

        vertex *secondNewVertex = new vertex;
        secondNewVertex->value = firstValue;
        secondNewVertex->next = G[secondValue];
        G[secondValue] = secondNewVertex;
    }

    return G;
}

int **createDirectedMatrixGraph(int v, int e)
{
    int **G = new int *[v];
    for (int i = 0; i < v; i++) G[i] = new int[v];
    
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            G[i][j] = 0;
        }
    }

    int firstValue, secondValue;

    for (int i = 0; i < e; i++)
    {
        std::cin >> firstValue >> secondValue;
        G[firstValue][secondValue] = 1;
    }

    return G;
}

int **createUndirectedMatrixGraph(int v, int e)
{
    int **G = new int *[v];
    for (int i = 0; i < v; i++) G[i] = new int[v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            G[i][j] = 0;
        }
    }

    int firstValue, secondValue;

    for (int i = 0; i < e; i++)
    {
        std::cin >> firstValue >> secondValue;
        G[firstValue][secondValue] = G[secondValue][firstValue] = 1;
    }

    return G;
}

int **createWeightedDirectedMatrixGraph(int v, int e)
{
    int **G = new int *[v];
    for (int i = 0; i < v; i++) G[i] = new int[v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            G[i][j] = 0;
        }
    }

    int firstValue, secondValue, weight;

    for (int i = 0; i < e; i++)
    {
        std::cin >> firstValue >> secondValue >> weight;
        G[firstValue][secondValue] = weight;
    }

    return G;
}

int **createWeightedUndirectedMatrixGraph(int v, int e)
{
    int **G = new int *[v];
    for (int i = 0; i < v; i++) G[i] = new int[v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            G[i][j] = 0;
        }
    }

    int firstValue, secondValue, weight;

    for (int i = 0; i < e; i++)
    {
        std::cin >> firstValue >> secondValue >> weight;
        G[firstValue][secondValue] = G[secondValue][firstValue] = weight;
    }

    return G;
}

void printListGraph(vertex **G, int v)
{
    vertex *tempVertex = NULL;

    for (int i = 0; i < v; i++)
    {
        tempVertex = G[i];
        std::cout << i <<": ";

        while (tempVertex)
        {
            std::cout << tempVertex->value << " ";
            tempVertex = tempVertex->next;
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void printMatrixGraph(int **G, int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            std::cout << G[i][j] << " ";
        }

        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}

void deleteListGraph(vertex **G, int v)
{
    vertex *current;
    vertex *next;

    for (int i = 0; i < v; i++)
    {
        current = G[i];

        while (current != NULL)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }
    delete [] G;
}

void deleteMatrixGraph(int **G, int v)
{
    for (int i = 0; i < v; i++)
    {
        delete [] G[i];
    }
    delete [] G;    
}

// PRIORITY QUEUE

int getLeftChild(int key)
{
    return key * 2 + 1;
}

int getRightChild(int key)
{
    return key * 2 + 2;
}

int getParent(int key) 
{
    return (key - 1) / 2;
}

void swapData(Data &a, Data &b) 
{
    Data tmp = a;
    a = b;
    b = tmp;
}

bool empty(PriorityQueue *heap)
{
    return heap->currentSize == 0 ? true : false;
}

PriorityQueue *createHeap(int size)
{
    PriorityQueue *heap = new PriorityQueue;

    heap->maxSize = size;
    heap->currentSize = 0;
    heap->queueArray = new Data[heap->maxSize];

    return heap;
}

bool heapInsertData(PriorityQueue *heap, int value, int priority)
{
    if (heap->currentSize == heap->maxSize) return false;

    heap->queueArray[heap->currentSize].value = value;
    heap->queueArray[heap->currentSize].priority = priority;

    int key = heap->currentSize;

    while (key > 0 && heap->queueArray[getParent(key)].priority > heap->queueArray[key].priority)
    {
        swapData(heap->queueArray[getParent(key)], heap->queueArray[key]);
        key = getParent(key);
    }

    heap->currentSize++;

    return true;
}

void heapify(PriorityQueue *heap, int key)
{
    int left = getLeftChild(key);
    int right = getRightChild(key);
    int min = key;

    if (left < heap->currentSize && heap->queueArray[left].priority < heap->queueArray[key].priority) min = left;  
    if (right < heap->currentSize && heap->queueArray[right].priority < heap->queueArray[min].priority) min = right; 

    if (min != key)
    {
        swapData(heap->queueArray[key], heap->queueArray[min]);
        heapify(heap, min);
    }
}

Data heapExtractData(PriorityQueue *heap)
{
    if(empty(heap))
    {
        Data errorData = {.value = INF, .priority = INF};
        return errorData;
    }

    Data min = heap->queueArray[0];
    heap->currentSize--;
    heap->queueArray[0] = heap->queueArray[heap->currentSize];
    heapify(heap, 0);

    return min;
}

void deleteHeap(PriorityQueue *heap)
{
    delete [] heap->queueArray;
    delete heap;
}