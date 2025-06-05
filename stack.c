#include <stdio.h>
#include <stdbool.h>

typedef struct Stack {
    int arr[100];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack) {
    return stack->top == 100;
}

void push(Stack *stack, int val) {
    if (isFull(stack))
    {
        printf("Stack Overflow.\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = val;
    printf("%d Added to Stack.\n", val);
}

int pop(Stack * stack) {
    if (isEmpty(stack))
    {
        printf("Stack Underflow.\n");
        return -1;
    }
    int popped = stack->arr[stack->top];
    stack->top--;
    printf("%d popped from Stack\n", popped);
    return popped;
}

int top(Stack *stack) {
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->arr[stack->top];
}

void main() {
    Stack stack;
    initialize(&stack);
    push(&stack, 10);
    push(&stack, 34);
    push(&stack, 50);
    pop(&stack);
    push(&stack, 13);
    push(&stack, 1);
    while (!isEmpty(&stack)) {
        pop(&stack);
    }

}