#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;


struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = new_node; 
    return new_node;
}


void insert_at_beginning(int value)
{
    struct node *new_node = create_node(value);

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    struct node *last = head;
    while (last->next != head)
        last = last->next;

    new_node->next = head;
    last->next = new_node;
    head = new_node;
}


void insert_at_end(int value)
{
    struct node *new_node = create_node(value);

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    struct node *last = head;
    while (last->next != head)
        last = last->next;

    last->next = new_node;
    new_node->next = head;
}


void insert_at_position(int value, int position)
{
    if (position == 1)
    {
        insert_at_beginning(value);
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head && position > 2)
    {
        printf("Position out of range\n");
        return;
    }

    struct node *new_node = create_node(value);
    new_node->next = temp->next;
    temp->next = new_node;
}


void delete_at_beginning()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node *last = head;
    while (last->next != head)
        last = last->next;

    struct node *temp = head;
    head = head->next;
    last->next = head;

    free(temp);
}


void delete_at_end()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}


void delete_at_position(int position)
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (position == 1)
    {
        delete_at_beginning();
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    for (int i = 1; i < position && temp->next != head; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head)
    {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Circular Singly Linked List Elements:\n");
    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void search(int value)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    int position = 1, found = 0;

    do
    {
        if (temp->data == value)
        {
            printf("Value %d found at position %d\n", value, position);
            found = 1;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    if (!found)
        printf("Value %d not found in the list.\n", value);
}

int main()
{
    int choice, value, position;
    char cont;

    do
    {
        printf("\n--- Circular Singly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
        case 8:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        default:
            printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    return 0;
}
