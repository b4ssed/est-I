#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct stack {
    int items[MAX_SIZE];
    int top;
} Stack;

void init(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack stack) {
    return stack.top == -1;
}

int isFull(Stack stack) {
    return stack.top == MAX_SIZE - 1;
}

void push(Stack* stack, int value) {
    if (isFull(*stack)) {
        printf("Stack overflow!\n");
    } else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (isEmpty(*stack)) {
        printf("Stack underflow!\n");
        return -1; // valor de erro
    } else {
        int value = stack->items[stack->top];
        stack->top--;
        return value;
    }
}

int top(Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1; // valor de erro
    } else {
        return stack.items[stack.top];
    }
}

void display(Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements:\n");
        for (int i = stack.top; i >= 0; i--) {
            printf("%d\n", stack.items[i]);
        }
    }
}

int main() {
    Stack stack;
    init(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    display(stack);
    printf("Top element: %d\n", top(stack));
    printf("Popped element: %d\n", pop(&stack));
    display(stack);
    return 0;
}
