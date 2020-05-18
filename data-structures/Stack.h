//
// created by Uladzislau Tumilovich
//

#ifndef STACK_H
#define STACK_H

#include <iostream>

struct Stack
{
    int *array;
    int size;
    int maxSize;
};

Stack *createStack(int maxSize);
bool isStackEmpty(Stack *stack);
bool isStackFull(Stack *stack);
bool push(Stack *stack, int value);
bool pop(Stack *stack);
int top(Stack *stack);
int stackSize(Stack *stack);
int stackMaxSize(Stack *stack);
void deleteStack(Stack *stack);

#endif //STACK_H