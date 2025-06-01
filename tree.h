// tree.h
#ifndef TREE_H
#define TREE_H
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

#endif