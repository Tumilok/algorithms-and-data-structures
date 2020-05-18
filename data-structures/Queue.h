//
// created by Uladzislau Tumilovich 
//

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

#define MIN INT16_MIN

struct Queue
{
    int *array;
    int front, back;
    int maxSize;
};

Queue *createQueue(int maxSize);
bool isQueueEmpty(Queue *queue);
bool isQueueFull(Queue *queue);
bool enqueue(Queue *queue, int value);
bool dequeue(Queue *queue);
int front(Queue *queue);
int back(Queue *queue);
int queueSize(Queue *queue);
int queueMaxSize(Queue *queue);
void deleteQueue(Queue *queue);

#endif //QUEUE_H