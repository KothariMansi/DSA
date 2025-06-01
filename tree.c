#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "tree.h"

void insertNode(Node **tree, int val) {
    Node* temp = NULL;
    if (!(*tree))
    {
        Node* temp = (Node*)malloc(sizeof(Node*));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if (val < (*tree)->data) {
        insertNode(&(*tree)->left, val);
    } else if (val > (*tree)->data) {
        insertNode(&(*tree)->right, val);
    }
}

void deltree(Node *tree) {
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

Node* searchtree(Node **tree, int val) {
    if (!(*tree))
    {
        return NULL;
    }
    if (val < (*tree)->data) {
        searchtree(&(*tree)->left, val);
    } else if (val > (*tree)->data)
    {
        searchtree(&(*tree)->right, val);
    } else if (val == (*tree)->data)
    {
        return *tree;
    }
}

void printPreorder(Node* tree) {
    if (tree)
    {
        printf("%d ", tree->data);
        printPreorder(tree->left);
        printPreorder(tree->right);
    }
}

void printInorder(Node *tree) {
    if (tree)
    {
        printInorder(tree->left);
        printf("%d ", tree->data);
        printInorder(tree->right);
    }  
}

void printpostorder(Node *tree) {
    if (tree)
    {
        printpostorder(tree->left);
        printpostorder(tree->right);
        printf("%d ", tree->data);
    }  
}

void printLevelorder(Node *tree) {
    if (!tree) return;
    Queue *queue = createQueue(100);
    enqueue(queue, tree);
    while (!isEmpty(queue))
    {
        Node *current = dequeue(queue);
        printf("%d ", current->data);
        if (current->left)
        {
            enqueue(queue, current->left);
        }
        if (current->right)
        {
            enqueue(queue, current->right);
        }
    }
    freeQueue(queue);
}

int main(void) {
    Node* root;
    root = NULL;
    insertNode(&root, 4);
    insertNode(&root, 2);
    insertNode(&root, 6);
    insertNode(&root, 1);
    insertNode(&root, 3);
    insertNode(&root, 5);
    insertNode(&root, 7);
    printPreorder(root);
    printf("\n");
    printInorder(root);
    printf("\n");
    printpostorder(root);
  
    printf("\n");
    printLevelorder(root);

    return 0;
}