#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include"string.h"
#include"image.h"

#define IMAGE_STACK_MAX_SIZE 20
typedef struct
{
    int tot;
    char path[20];
    ImageData stackData[IMAGE_STACK_MAX_SIZE + 2];
    int base;
}Stack;


void stackInit(Stack *stack);
void stackPush(Stack *stack,Image *image);
int stackPop(Stack *stack,Image *image);

#endif