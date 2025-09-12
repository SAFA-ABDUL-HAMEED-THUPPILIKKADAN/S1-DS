#include <stdio.h>
#define MAX 100

int arr[MAX];
int n = 0; 


void insert(int value)
{
    if (n == MAX)
    {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    arr[n] = value;
    n++;
}


void delete_last()
{
    if (n == 0)
    {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    printf("Deleted element: %d\n", arr[n - 1]);
    n--;
}


void search(int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            printf("Value %d found at position %d\n", value, i + 1);
            return;
        }
    }
    printf("Value %d not found in array.\n", value);
}


void display()
{
    if (n == 0)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int choice, value;
    char cont;

    do
    {
        printf("\n--- Array Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            delete_last();
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 4:
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
