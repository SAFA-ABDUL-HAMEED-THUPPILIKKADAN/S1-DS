#include<stdio.h>
#define MAX 10
int stack[MAX];
int top = -1;

void push (int value) {
    if (top == MAX - 1) {
        printf("Overflow\n");
        return;
    } else {
        top++;
        stack[top] = value;
        printf("%d is pushed to the stack\n", stack[top]);
    }
}

void pop () {
    int n;
    if (top == -1) {
        printf("Underflow\n");
    } else {
        n = stack[top];
        top--;
        printf("Deleted %d from the stack\n", n);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value, cont;

    do {
        printf("\nEnter your choice:\n1) Push\n2) Pop\n3) Display\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be added to the stack:\n");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
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
