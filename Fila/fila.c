#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

void init(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue q) {
    return q.front == NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(*q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue* q) {
    if (isEmpty(*q)) {
        printf("Queue underflow!\n");
    } else {
        Node* temp = q->front;
        printf("Dequeued element: %d\n", temp->data);
        q->front = temp->next;
        free(temp);
        if (q->front == NULL) {
            q->rear = NULL;
        }
    }
}

void display(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        Node* temp = q.front;
        printf("Queue elements:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(q);
    dequeue(&q);
    dequeue(&q);
    display(q);
    return 0;
}
