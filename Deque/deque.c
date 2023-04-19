#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

typedef struct deque {
    Node* front;
    Node* rear;
} Deque;

void init(Deque* dq) {
    dq->front = dq->rear = NULL;
}

int isEmpty(Deque dq) {
    return dq.front == NULL;
}

void insertFront(Deque* dq, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = dq->front;
    newNode->prev = NULL;
    if (isEmpty(*dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
        dq->front = newNode;
    }
}

void insertRear(Deque* dq, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;
    if (isEmpty(*dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
}

void deleteFront(Deque* dq) {
    if (isEmpty(*dq)) {
        printf("Deque underflow!\n");
    } else {
        Node* temp = dq->front;
        printf("Deleted element: %d\n", temp->data);
        dq->front = temp->next;
        if (dq->front == NULL) {
            dq->rear = NULL;
        } else {
            dq->front->prev = NULL;
        }
        free(temp);
    }
}

void deleteRear(Deque* dq) {
    if (isEmpty(*dq)) {
        printf("Deque underflow!\n");
    } else {
        Node* temp = dq->rear;
        printf("Deleted element: %d\n", temp->data);
        dq->rear = temp->prev;
        if (dq->rear == NULL) {
            dq->front = NULL;
        } else {
            dq->rear->next = NULL;
        }
        free(temp);
    }
}

void display(Deque dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
    } else {
        Node* temp = dq.front;
        printf("Deque elements:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    Deque dq;
    init(&dq);
    insertFront(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 30);
    insertRear(&dq, 40);
    display(dq);
    deleteFront(&dq);
    deleteRear(&dq);
    display(dq);
    return 0;
}