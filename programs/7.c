#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;


struct node *create(int data) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void insert_end(int data) {
    struct node *newnode = create(data);

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}


void insert_left(int new_data, int key_value) {
    struct node *newnode = create(new_data);

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node *current = head;

    while (current != NULL && current->data != key_value)
        current = current->next;

    if (current == NULL) {
        printf("Key %d not found. Insert failed.\n", key_value);
        free(newnode);
        return;
    }

    newnode->next = current;
    newnode->prev = current->prev;

    if (current->prev != NULL)
        current->prev->next = newnode;
    else
        head = newnode;

    current->prev = newnode;
}

void delete_spec(int key) {
    struct node *current = head;

    while (current != NULL && current->data != key)
        current = current->next;

    if (current == NULL) {
        printf("Value %d not found. Cannot delete.\n", key);
        return;
    }

    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    printf("Node %d deleted.\n", key);
}

void search(int key) {
    struct node *current = head;
    int pos = 1;

    while (current != NULL) {
        if (current->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        pos++;
        current = current->next;
    }
    printf("Element %d not found\n", key);
}


void display() {
    struct node *temp = head;

    printf("DLL: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {

printf("NAME:CHAITRA M \n");
printf("USN:1BM24CS078 \n");

    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);

    printf("Initial List:\n");
    display();


    insert_left(15, 20);
    printf("\nAfter inserting 15 left of 20:\n");
    display();

    delete_spec(30);
    printf("\nAfter deleting 30:\n");
    display();

}
