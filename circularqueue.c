#include <stdio.h>
#define MAX 5   

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if ((rear + 1) % MAX == front)   
    {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1) 
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
    printf("%d enqueued to queue\n", value);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }

    int x = queue[front];
    if (front == rear) 
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
    printf("%d dequeued from queue\n", x);
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    int choice, value, cont;

    do
    {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n");
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

        printf("\nDo you want to continue? (1 = Yes / 0 = No): ");
        scanf("%d", &cont);

    } while (cont == 1);

    printf("Program terminated.\n");
    return 0;
}
