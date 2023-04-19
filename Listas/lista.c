#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct linkedList {
    Node* head;
    int size;
} LinkedList;

void init(LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

int isEmpty(LinkedList list) {
    return list.head == NULL;
}

void addFirst(LinkedList* list, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void addLast(LinkedList* list, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(*list)) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

int removeFirst(LinkedList* list) {
    if (isEmpty(*list)) {
        printf("List underflow!\n");
        return -1; // valor de erro
    } else {
        Node* temp = list->head;
        int value = temp->data;
        list->head = temp->next;
        free(temp);
        list->size--;
        return value;
    }
}

int removeLast(LinkedList* list) {
    if (isEmpty(*list)) {
        printf("List underflow!\n");
        return -1; // valor de erro
    } else {
        Node* temp = list->head;
        if (temp->next == NULL) { // apenas um elemento
            int value = temp->data;
            free(temp);
            list->head = NULL;
            list->size--;
            return value;
        } else {
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            int value = temp->next->data;
            free(temp->next);
            temp->next = NULL;
            list->size--;
            return value;
        }
    }
}

int search(LinkedList list, int key) {
    Node* temp = list.head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1; // chave não encontrada
}

void display(LinkedList list) {
    if (isEmpty(list)) {
        printf("List is empty!\n");
    } else {
        Node* temp = list.head;
        printf("List elements:\n");
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    LinkedList list;
    init(&list);
    addLast(&list, 10);
    addLast(&list, 20);
    addFirst(&list, 30);
    addFirst(&list, 40);
    display(list);
    removeFirst(&list);
    remove
}