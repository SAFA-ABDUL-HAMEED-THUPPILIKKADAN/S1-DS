#include<stdio.h>
#define MAX 10
int queue[MAX];
int front = -1,rear=-1;


void enqueue(int value)
{
    if (rear == MAX-1)  {
        printf("Overflow");
    }
    else {
        if (front == -1 && rear == -1)  {
            front = 0, rear = 0;
            queue[rear] = value;
        }
        else {
            rear++;
            queue[rear] = value;
        }

    }
}



void dequeue()
{
    if (front == -1)  {
        printf("Underflow");
    }
    else {
        if (front == rear)  {
            int x = queue[front];
            front = -1, rear = -1;
            printf("%d is deleted from the queue",x);
        }
        else {
            int x = queue[front];
            front++;
            printf("%d is deleted from the queue",x);

        }
        

    }
}

void display() {
  if (front == -1)  {
     printf("No elements in the queue");
  }
else {
    for (int i = front; i <= rear; i++)   {
        printf("%d ",queue[i]);
    }
}


}


int main() {
    int choice, value, cont;

    do {
        printf("\nEnter your choice:\n1) Enqueue\n2) Dequeue\n3) Display\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be added to the queue:\n");
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
                printf("Invalid choice\n");
        }

        printf("\nDo you want to continue? (1 = Yes / 0 = No): ");
        scanf("%d", &cont);

    } while (cont == 1);

    printf("Program terminated.\n");
    return 0;
}
