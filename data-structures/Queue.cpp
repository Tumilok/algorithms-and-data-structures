//
// created by Uladzislau Tumilovich 
//

#include "Queue.h"

// Function creates Queue
Queue *createQueue(int maxSize)
{
    Queue *queue = new Queue;
    queue->array = new int[maxSize];
    queue->front = queue->back = -1;
    queue->maxSize = maxSize;

    return queue;
}

// Function checks whether Queue is empty or not
bool isQueueEmpty(Queue *queue)
{
    return queue->front == -1 && queue->back == -1 ? true : false;
}

// Function checks whether Queue is full or not
bool isQueueFull(Queue *queue)
{
    return (queue->front + 1) % queue->maxSize == queue->back ? true : false;
}

// Function inserts integer into Queue 
bool enqueue(Queue *queue, int value)
{
    if (isQueueFull(queue)) return false;
    else if(queue->front == -1 && queue->back == -1) queue->front = queue->back = 0;
    else queue->front = (queue->front + 1) % queue->maxSize;

    queue->array[queue->front] = value;
    return true;
}

// Function removes integer from Queue
bool dequeue(Queue *queue)
{
    if (isQueueEmpty(queue)) return false;
    else if(queue->front == queue->back) queue->front = queue->back = -1;
    else queue->back = (queue->back + 1) % queue->maxSize;
    
    return true;
}

// Function gives front integer of Queue
int front(Queue *queue)
{
    if (isQueueEmpty(queue)) return MIN;
    else return queue->array[queue->front];
}

// Function gives back integer of Queue
int back(Queue *queue)
{
    if (isQueueEmpty(queue)) return MIN;
    else return queue->array[queue->back];
}

// Function gives current size of Queue
int queueSize(Queue *queue)
{
    if (isQueueEmpty(queue)) return 0;
    else if (queue->front >= queue->back) return queue->front - queue->back + 1;
    else return (queue->maxSize - queue->back) + (queue->front + 1);
}

// Function gives max size of Stack
int queueMaxSize(Queue *queue)
{
    return queue->maxSize;
}

// Function deletes Queue
void deleteQueue(Queue *queue)
{
    delete [] queue->array;
    delete queue;
}