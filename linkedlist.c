#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;

struct node* create_node(int data, struct node *link) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = link;
    return new_node;
}

void insert_at_beginning(int value) {
    struct node *new_node = create_node(value, head);
    head = new_node;
}

void insert_at_position(int value, int position) {
    struct node *new_node;
    struct node *temp = head;

    if (position == 1) {
        insert_at_beginning(value);
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    new_node = create_node(value, temp->link);
    temp->link = new_node;
}

void insert_at_end(int value) {
    struct node *new_node = create_node(value, NULL);

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node *i;
    for (i = head; i->link != NULL; i = i->link);
    i->link = new_node;
}

void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *temp = head;
    head = head->link;
    free(temp);
}

void delete_at_position(int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (position == 1) {
        delete_at_beginning();
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    prev->link = temp->link;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->link == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }

    prev->link = NULL;
    free(temp);
}

void display() {
    
    printf("Linked List Elements are:\n");
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    for (struct node *i = head; i != NULL; i = i->link) {
        printf("%d ", i->data);
    }
    printf("\n");
}

int main() {
    int choice, value, position;
    char cont;

    do {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_at_beginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_at_end(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &position);
                insert_at_position(value, position);
                break;
            case 4:
                delete_at_beginning();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                delete_at_position(position);
                break;
            case 7:
                display();
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &cont); // space before %c to consume newline character

    } while(cont == 'y' || cont == 'Y');

    return 0;
}


