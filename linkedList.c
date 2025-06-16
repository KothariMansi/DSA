#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertAtBeginning(struct node** root, int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Overflow");
        return;
    }
    
    temp->data = val;
    temp->next = *root;
    *root = temp;
}

void insertAtEnd(struct node** root, int val) {
    while (*root != NULL)
    {
        root = (&(*root)->next);
    }
    
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Overflow");
        return;
    }
    *root = temp;
    (*root)->data = val;
    (*root)->next = NULL;
}

void insertAtSpecificLocation(struct node** root, int val, int pos) {
    while ((*root)->data != pos)
    {
        root = (&(*root)->next);
    }
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = (*root)->next;
    (*root)->next = temp;
}

void display(struct node* root) {
    if (root == NULL) {  printf("\n"); return; }
    printf("%d ", root->data);
    display(root->next);

}

void deletionAtBeginning(struct node** root) {
    if (root)
    {
        *root = (*root)->next;
    }
}

void deleteAtSpecificLocation(struct node** root, int pos) {
    while ((*root)->data != pos)
    {
        root = (&(*root)->next);
    }
    (*root)->next = (*root)->next->next;
}

void deletionAtEnd(struct node** root) {
    if (*root == NULL)
    {
        return;
    } 
    if ((*root)->next == NULL)
    {
        *root = NULL;
        return;
    }
    struct node *temp = *root;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}


void search(struct node* root, int val) {
    int count = 0;
    while (root->data != val)
    {
        if (root->next == NULL)
        {
            printf("Not Found\n");
            return;
        }
        root = root->next;
        count++;
    }
    printf("Element Found at postion %d\n", count);
}

int main() {
    struct node *head = NULL;
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 4);
    insertAtBeginning(&head, 7);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 10);
    insertAtSpecificLocation(&head, 12, 5);
    display(head);
    search(head, 4);
    deletionAtBeginning(&head);
    display(head);
    deleteAtSpecificLocation(&head, 5);
    display(head);
    deletionAtEnd(&head);
    deletionAtEnd(&head);
    display(head);
    return 0;
}