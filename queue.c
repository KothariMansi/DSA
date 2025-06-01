#include <stdlib.h>
#include "queue.h"

Queue* createQueue(int capacity) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (Node **)malloc(q->capacity * sizeof(Node*));
    return q;
}

int isEmpty(Queue *q) {
    return q->size == 0;  
}

void enqueue(Queue *q, Node *node) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1 ) % q->capacity;
    q->arr[q->rear] =node;
    q->size++;
}

Node* dequeue(Queue *q) {
    if (isEmpty(q)) return NULL;
    Node *node = q->arr[q->front];
    q->front = (q-> front + 1) % q->capacity;
    q->size--;  
    return node;  
}

void freeQueue(Queue *q) {
    free(q->arr);
    free(q);
}