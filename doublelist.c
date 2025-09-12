#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;


struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}


void insert_at_beginning(int value)
{
    struct node *new_node = create_node(value);
    if (head != NULL)
    {
        new_node->next = head;
        head->prev = new_node;
    }
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

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}


void insert_at_position(int value, int position)
{
    if (position == 1)
    {
        insert_at_beginning(value);
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    struct node *new_node = create_node(value);
    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = new_node;
    }

    temp->next = new_node;
}


void delete_at_beginning()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}


void delete_at_end()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
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
    for (int i = 1; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        return;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    free(temp);
}


void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List Elements:\n");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void search(int value)
{
    struct node *temp = head;
    int position = 1;
    int found = 0;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Value %d found at position %d\n", value, position);
            found = 1;
        }
        temp = temp->next;
        position++;
    }

    if (!found)
    {
        printf("Value %d not found in the list.\n", value);
    }
}

int main()
{
    int choice, value, position;
    char cont;

    do
    {
        printf("\n--- Doubly Linked List Operations ---\n");
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
