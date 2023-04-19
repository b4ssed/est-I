#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

typedef struct list {
    Node* head;
    Node* tail;
} List;

void init(List* list) {
    list->head = NULL;
    list->tail = NULL;
}

int isEmpty(List list) {
    return list.head == NULL;
}

void insert(List* list, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (isEmpty(*list)) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

void delete(List* list, int value) {
    if (isEmpty(*list)) {
        printf("List is empty!\n");
    } else {
        Node* current_node = list->head;
        while (current_node != NULL && current_node->data != value) {
            current_node = current_node->next;
        }
        if (current_node == NULL) {
            printf("Element not found!\n");
        } else if (current_node == list->head && current_node == list->tail) {
            list->head = NULL;
            list->tail = NULL;
            free(current_node);
        } else if (current_node == list->head) {
            list->head = current_node->next;
            list->head->prev = NULL;
            free(current_node);
        } else if (current_node == list->tail) {
            list->tail = current_node->prev;
            list->tail->next = NULL;
            free(current_node);
        } else {
            current_node->prev->next = current_node->next;
            current_node->next->prev = current_node->prev;
            free(current_node);
        }
    }
}

void search(List list, int value) {
    if (isEmpty(list)) {
        printf("List is empty!\n");
    } else {
        Node* current_node = list.head;
        while (current_node != NULL && current_node->data != value) {
            current_node = current_node->next;
        }
        if (current_node == NULL) {
            printf("Element not found!\n");
        } else {
            printf("Element found: %d\n", current_node->data);
        }
    }
}

void display(List list) {
    if (isEmpty(list)) {
        printf("List is empty!\n");
    } else {
        printf("List elements (from head to tail):\n");
        Node* current_node = list.head;
        while (current_node != NULL) {
            printf("%d\n", current_node->data);
            current_node = current_node->next;
        }
    }
}

int main() {
    List list;
    init(&list);
    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);
    insert(&list, 40);
    display(list);
    delete(&list, 30);
    display(list);
    search(list, 20);
    return 0;
}