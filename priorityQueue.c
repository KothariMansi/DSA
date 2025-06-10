#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void insert_by_priority(int);
void delete_by_priority(int);
void create();
void check(int);
void display_pqueue();
int pri_queue[MAX];
int front, rear;

int main() {
    int n, ch;
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");
    create();
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value to be inserted: ");
            scanf("%d", &n);
            insert_by_priority(n);
            break;

        case 2:
            printf("\nEnter value to be deleted: ");
            scanf("%d", &n);
            delete_by_priority(n);
            break;

        case 3:
            display_pqueue();
            break;

        case 4:
           exit(0);
        
        default:
            printf("\nChoice is incorrect, Enter a correct choice: ");
            break;
        }
    }

    return 0;
}

void create() {
    front = rear = -1;
}

void insert_by_priority(int data) {
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        pri_queue[rear] = data;
        return;
    } else
    {
        check(data);
        rear++;
    }
}

void check(int data) {
    int i, j;
    for (i = 0; i<= rear; i++) {
        if (data >= pri_queue[i])
        {
            for (j = rear + 1; j > i; j--) {
                pri_queue[j] = pri_queue[j - 1];
            }
            pri_queue[i] = data;
            return;
        }   
    }
    pri_queue[i] = data;
}

void delete_by_priority(int data) {
    int i;
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
    for (i = 0; i <= rear; i++) {
        if (data == pri_queue[i])
        {
            for (; i < rear; i++)
            {
                pri_queue[i] = pri_queue[i + 1];
            }
            pri_queue[i] = -99;
            rear--;
            if (rear == -1)
            {
                front = -1;
            }
            printf("\nDeleted");
            return;
        } 
    }
    printf("\n%d Not found in queue to delete", data);
    return;
}

void display_pqueue() {
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
        return;
    }
    for (; front <= rear; front++)
    {
        printf(" %d", pri_queue[front]);
    }
    front = 0;
}