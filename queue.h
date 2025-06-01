#ifndef QUEUE_H
#define QUEUE_H

#include "tree.h"

typedef struct Queue
{
    Node **arr;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity);
int isEmpty(Queue *q);
void enqueue(Queue *q, Node *n);
Node *dequeue(Queue *q);
void freeQueue(Queue *q);

#endif