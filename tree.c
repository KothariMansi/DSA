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

void helper(Node **tree, Node **NodeAdd){
    if (!(*tree))  {
        tree = NodeAdd;
        return;
    }
    if ((*NodeAdd)->data < (*tree)->data) {
        helper(&(*tree)->left, NodeAdd);
    }
    if ((*NodeAdd)->data > (*tree)->data) {
        helper(&(*tree)->right, NodeAdd);
    }
}


Node* findMin(Node *root) {
    if (root->left != NULL) {
        return findMin(root->left);
    } else {
        return root;
    }
}

Node* delNode(Node *root, int val) {
    if (root == NULL) return NULL;
    else {
        if (val < root->data) {
            root->left = delNode(root->left, val); 
        }  else if (val > root->data)  {
            root->right = delNode(root->right, val);
        }  else {
            // 4 conditions
            if (root->left == NULL && root->right==NULL) {
                root = NULL;
            } else if (root->left == NULL){
                root = root->right;
            } else if (root->right == NULL) {
                root = root->left;
            } else {
                Node* temp = findMin(root->right);
                root->data = temp->data;
                root->right = delNode(root->right, temp->data);
            } 
        } 
        return root;
    }
}


Node* searchtree(Node **tree, int val) {
    if (!(*tree))
    {
        return NULL;
    }
    if (val < (*tree)->data) {
        searchtree(&(*tree)->left, val);
    } else if (val > (*tree)->data){
        searchtree(&(*tree)->right, val);
    } else if (val == (*tree)->data){
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

int checkCompleteBinaryTree(Node *tree) {
    if (!tree) return 0;
    Queue *queue = createQueue(100);
    enqueue(queue, tree);
    int flag = 0;
    while (!isEmpty(queue))
    {
        Node *current = dequeue(queue);
        if (current->left)
        {
            if (flag == 1) return 0;
            enqueue(queue, current->left);
        } else {
            flag = 1;
        }
        if (current->right)
        {
            if (flag == 1)  return 0;
            enqueue(queue, current->right);
        } else {
            flag = 1;
        }
    }
    freeQueue(queue);
    return 1;
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
    int res = checkCompleteBinaryTree(root);
    printf("\n");
    if (res == 0)
    {
        printf("No");
    } else {
        printf("Yes");
    }
    printf("\n");
    delNode(root, 2);
    printInorder(root);

    return 0;
}