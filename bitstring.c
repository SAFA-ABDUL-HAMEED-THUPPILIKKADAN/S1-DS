#include <stdio.h>
#include <string.h>

// Check for duplicate elements in the universal set
int duplicate(int set[], int size, int n)
{
    for (int i = 0; i < size; i++)
    {
        if (set[i] == n)
        {
            printf("The element already exists in the set.\n");
            return 1;
        }
    }
    return 0;
}

// Perform set operations using bit strings
void operations(char bitstring_1[], char bitstring_2[], int set[], char op)
{
    int len = strlen(bitstring_1);
    char result[20];
    int first = 1;

    if (op == 'u')
    {
        printf("\nUnion of sets: {");
        for (int i = 0; i < len; i++)
            result[i] = (bitstring_1[i] == '1' || bitstring_2[i] == '1') ? '1' : '0';
    }
    else if (op == 'i')
    {
        printf("\nIntersection of sets: {");
        for (int i = 0; i < len; i++)
            result[i] = (bitstring_1[i] == '1' && bitstring_2[i] == '1') ? '1' : '0';
    }
    else if (op == 'd')
    {
        printf("\nDifference of sets (A - B): {");
        for (int i = 0; i < len; i++)
            result[i] = (bitstring_1[i] == '1' && bitstring_2[i] == '0') ? '1' : '0';
    }
    else if (op == 'a') // Complement of A
    {
        printf("\nComplement of Set 1 (A'): {");
        for (int i = 0; i < len; i++)
            result[i] = (bitstring_1[i] == '0') ? '1' : '0';
    }
    else if (op == 'b') // Complement of B
    {
        printf("\nComplement of Set 2 (B'): {");
        for (int i = 0; i < len; i++)
            result[i] = (bitstring_2[i] == '0') ? '1' : '0';
    }

    // Print result set properly without trailing comma
    for (int i = 0; i < len; i++)
    {
        if (result[i] == '1')
        {
            if (!first)
                printf(",");
            printf("%d", set[i]);
            first = 0;
        }
    }
    printf("}");
}

int main()
{
    int l, n, set[20];
    printf("Enter the size of universal set: ");
    scanf("%d", &l);

    printf("Enter the elements: ");
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &n);
        if (duplicate(set, i, n) == 0)
            set[i] = n;
        else
            i--; // re-enter if duplicate
    }

    printf("The Universal set: {");
    for (int i = 0; i < l; i++)
    {
        printf("%d", set[i]);
        if (i != l - 1)
            printf(",");
    }
    printf("}");

    char bitstring_1[20], bitstring_2[20];
    printf("\nEnter the first bitstring set: ");
    scanf("%s", bitstring_1);
    printf("Enter the second bitstring set: ");
    scanf("%s", bitstring_2);

    // Display Set 1
    printf("Set 1: {");
    int first = 1;
    for (int i = 0; i < l; i++)
    {
        if (bitstring_1[i] == '1')
        {
            if (!first)
                printf(",");
            printf("%d", set[i]);
            first = 0;
        }
    }
    printf("}");

    // Display Set 2
    printf("\nSet 2: {");
    first = 1;
    for (int i = 0; i < l; i++)
    {
        if (bitstring_2[i] == '1')
        {
            if (!first)
                printf(",");
            printf("%d", set[i]);
            first = 0;
        }
    }
    printf("}");

    // Perform set operations
    operations(bitstring_1, bitstring_2, set, 'u');
    operations(bitstring_1, bitstring_2, set, 'i');
    operations(bitstring_1, bitstring_2, set, 'd');
    operations(bitstring_1, bitstring_2, set, 'a'); 
    operations(bitstring_1, bitstring_2, set, 'b'); 

    return 0;
}
