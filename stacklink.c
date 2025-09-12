
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

void push(struct node **top, int value)
{
    struct node *newNode = create_node(value);
    newNode->link = *top;
    *top = newNode;
    printf("%d pushed to stack\n", value);
}

void pop(struct node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow!");
    }
    struct node *temp = *top;
    *top = (*top)->link;
    printf("%d popped from the stack\n", temp->data);
    free(temp);
}

void display(struct node *top)
{
    if (top == NULL)
    {
        printf("Stack empty!");
    }
    struct node *temp = top;
    printf("Stack: ");
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
    struct node *stack = NULL;

    do
    {
        printf("\n--- Stack operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            pop(&stack);
            break;
        case 3:
            display(stack);
            break;

        default:
            printf("Invalid choice!\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    return 0;
}