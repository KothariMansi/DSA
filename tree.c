#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;

} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
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

void print_levelorder(Node *tree) {
    if (tree)
    {
        printf("%d", tree->data);
        print_levelorder(tree->left);
        print_levelorder(tree->right);
    }
    
    
}

int main(void) {
    Node* root = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    root->left = node2;
    root->right = node3;
    node2->left = createNode(4);
    node2->right = createNode(5);
    node3->right = createNode(7);
    printPreorder(root);
    printf("\n");
    printInorder(root);
    printf("\n");
    printpostorder(root);

    return 0;
}