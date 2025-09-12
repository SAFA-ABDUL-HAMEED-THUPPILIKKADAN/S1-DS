
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}


void enqueue(int value)
{
    struct node *newNode = create_node(value);

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->link = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}


void dequeue()
{
    if (front == NULL)
    {
        printf("Queue underflow! Nothing to dequeue.\n");
        return;
    }

    struct node *temp = front;
    printf("%d dequeued from queue\n", temp->data);
    front = front->link;

    if (front == NULL) 
        rear = NULL;

    free(temp);
}


void display()
{
    if (front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }

    struct node *temp = front;
    printf("Queue (front to rear): ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main()
{
    int choice, value;
    char cont;

    do
    {
        printf("\n--- Queue operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    return 0;
}
