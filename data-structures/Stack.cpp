//
// created by Uladzislau Tumilovich
//

#include "Stack.h"

// Function creates Stack
Stack *createStack(int maxSize)
{
    Stack *stack = new Stack;
    stack->array = new int[maxSize];
    stack->size = -1;
    stack->maxSize = maxSize;

    return stack;
}

// Function checks whether Stack is empty or not
bool isStackEmpty(Stack *stack)
{
    return stack->size == -1 ? true : false;
}

// Function checks whether Stack is full or not
bool isStackFull(Stack *stack)
{
    return stack->size + 1 == stack->maxSize ? true : false;
}

// Function inserts interger into Stack
bool push(Stack *stack, int value)
{
    if (isStackFull(stack)) return false;

    stack->array[++stack->size] = value;  
    return true;
}

// Function removes integer from Stack
bool pop(Stack *stack)
{
    if (isStackEmpty(stack)) return false;

    stack->size--;
    return true;
}

// Function gives top integer of Stack
int top(Stack *stack)
{
    if (isStackEmpty(stack)) return INT16_MIN;
    else return stack->array[stack->size];
}

// Function gives current size of Stack
int stackSize(Stack *stack)
{
    return stack->size + 1;
}

// Function gives max size of Stack
int stackMaxSize(Stack *stack)
{
    return stack->maxSize;
}

// Function deletes Stack
void deleteStack(Stack *stack)
{
    delete [] stack->array;
    delete stack;
}