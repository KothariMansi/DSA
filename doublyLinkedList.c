#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node* next;
};

void insertAtbeginning(struct node **head, int val) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {printf("Overflow\n"); return;}
    temp->prev = NULL;
    temp->data = val;
    temp->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = temp; 
    }
    *head = temp;
}

void insertAtEnd(struct node** head, int val) {
    if (*head == NULL)
    {
        insertAtbeginning(head, val);
        return;
    }
    struct node* current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->prev = current;
    temp->next = NULL;
    current->next = temp;    
}

void insertAtPos(struct node** head, int val, int pos) {
    if (*head == NULL)
    {
        insertAtbeginning(head, val);
    }
    if (pos == 1)
    {
        insertAtbeginning(head, val);
    }
    struct node* current = *head;
    int count = 1;
    while (count + 1 != pos)
    {
        current = current->next;
        count++;
    }
    if (current->next == NULL)
    {
        insertAtEnd(head, val);
        return;
    }
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = current->next;
    temp->prev = current;
    current->next = temp;
    temp->next->prev = temp;
}


void deleteAtBeginning(struct node **head) {
    if (*head == NULL)
    {
        return;
    }
    struct node *next = (*head)->next;
    next->prev = NULL;
    (*head)->next = NULL;
    *head = next;
}

void deleteAtEnd(struct node** head) {
    if (*head == NULL)
    {
        return;
    } 
    struct node* current = *head;
    if (current->next == NULL)
    {
        free(current);
        *head = NULL;
    }
    
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->prev->next = NULL;
    current = NULL;
}

void deleteAtPos(struct node** head, int pos) {
    if (*head == NULL)
    {
        return;
    } if (pos == 1)
    {
        deleteAtBeginning(head);
    }
    
    struct node* current = *head;
    int count = 1;
    while (count+ 1 != pos)
    {
        current = current->next;
        count++;
    }
    if (current->next == NULL) { return; }
    if (current->next->next == NULL)
    {
        current->next = NULL;
        return;
    } 
    current->next = current->next->next;
    current->next->prev = current;
}

void display(struct node *head) {
    printf("Display      ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void displayBack(struct node *head) {
    printf("Display Back ");
    if (head == NULL)
    {
        return;
    }
    // Move to the last Node
    while (head->next != NULL)
    {
        head = head->next;
    }
    // Print in reverse
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

void search(struct node *head, int val) {
    if (head == NULL)
    {
        printf("Empty List\n");
    }
    int count = 1;
    while (head->data != val)
    {
        head = head->next;
        if (head == NULL)
        {
            printf("Not Found\n");
            return;
        }
        count = count + 1;
    }
    printf("Elelment found at pos %d\n", count);
}

int main() {
    struct node *head = NULL;
    insertAtbeginning(&head, 2);
    insertAtbeginning(&head, 6);
    insertAtbeginning(&head, 3);
    display(head);
    displayBack(head);
    deleteAtBeginning(&head);
    display(head);
    displayBack(head);
    insertAtbeginning(&head, 7);
    display(head);
    displayBack(head);
    insertAtEnd(&head, 10);
    display(head);
    displayBack(head);
    insertAtPos(&head, 0, 3); // 7 6 0 2 10
    display(head);
    displayBack(head);
    search(head, 2);
    search(head, 7);
    deleteAtEnd(&head); // 7 6 0 2
    display(head);
    displayBack(head);
    deleteAtPos(&head, 2); // 7 0 2
    display(head);
    search(head, 2);
    displayBack(head);
    deleteAtEnd(&head); // 7 0
    display(head);
    displayBack(head);
    return 0;
}