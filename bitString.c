#include<stdio.h>
#include<stdlib.h>

int max = 10;


int isDuplicate(int arr[], int v, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == v) {
            printf("Element already present in the set\n ");
            return 1;
        }
    }

    return 0;
}


int isUniversal(int U[], int v, int n) {
    int c = 0;
    for (int i = 0; i < n; i++) {

        if (U[i] == v) {
            c = 1;
            return 1;
        }
    }

    if (c == 0) {
        printf("Element not present in the universal set\n");
        return 0;
    }
}


void bitString(int U[],int A[],int BA[],int sa) {
 
    int k = 0;

    while (k != max) {
        for (int i = 0; i < sa; i++) {
            if (U[k] == A[i]) {
                BA[k] = 1;
                break;
            }

            else {
                BA[k] = 0;
            }

          
        }
          k++;
    }

}

void set_union(int a[], int b[], int c[]) {
    int k = 0;

    while (k != max) {
        if (a[k] == 1 || b[k] == 1) {
            c[k] = 1;
        }
        else {
            c[k] = 0;
        }
        k++;
    }
}


void set_intersection(int a[], int b[], int c[]) {
    int k = 0;

    while (k != max) {
        if (a[k] == 1 && b[k] == 1) {
            c[k] = 1;
        }

        else {
            c[k] = 0;
        }

        k++;
    }
}

void set_difference(int a[], int b[]) {

    int c[max];

    int k = 0;

    while (k != max) {
        if (a[k] == 1 && b[k] == 0) {
            c[k] = 1;
        }
        else {
            c[k] = 0;
        }

        k++;
    }

    for (int i = 0; i < max; i++) {
        printf("%d ",c[i]);
    }


}

void main() {
    int a, b, sa, sb, k = 0;

    printf("Enter the size of the Universal Set: ");
    scanf("%d", &max);

    int U[max], A[max], B[max], BA[max], BB[max], union_set[max], intersection[max], v;

    printf("Enter UNIVERSAL SET ELEMENTS: \n ");

    for (int i = 0; i < max; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d",&v);

        if (isDuplicate(U,v,i) == 0){
            U[i] = v;
        }
        else {
            i--;
        }
    }

    printf("\nUniversal Set Elements:\n ");
    for (int i = 0; i < max; i++) {
        printf("%d ", U[i]);
    }

    printf("\nEnter the size of set A: ");
    scanf("%d", &sa);

    if (sa > max) {
        printf("Size limit is %d, now size is set to %d", max, max);
        sa = max;

    }

    printf("\nEnter Set A Elements: \n");
    for (int i = 0; i < sa; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &v);
        a = isDuplicate(A,v,i);
        b = isUniversal(U,v,max);

        if ( a == 0 && b == 1) {
            A[i] = v;
        }

        else {
            i--;
        }
    }

    printf("\n SET A ELEMENTS: ");
    for (int i = 0; i < sa; i++) {
        printf("%d ", A[i]);

    }



    printf("\nEnter the size of set B: ");
    scanf("%d", &sb);

    if (sb > max) {
        printf("Size limit is %d, now size is set to %d ", max, max);
        sb = max;

    }

    printf("\nEnter Set B Elements: \n");
    for (int i = 0; i < sb; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &v);
        a = isDuplicate(B,v,i);
        b = isUniversal(U,v,max);

        if ( a == 0 && b == 1) {
            B[i] = v;
        }

        else {
            i--;
        }
    }

    printf("\n SET B ELEMENTS: ");
    for (int i = 0; i < sb; i++) {
        printf("%d ", B[i]);
        
    }

    bitString(U,A,BA,sa);

    printf("\n\n Bit Representation of Set A: ");

    for (int i = 0; i < max; i++) {
        printf("%d ", BA[i]);
    }

    bitString(U,B,BB,sb);

    printf("\n\n Bit Representation of Set B: ");

    for (int i = 0; i < max; i++) {
        printf("%d ", BB[i]);
    }

    printf("\n\nUnion of Set A and B: ");
    set_union(BA, BB, union_set);
    for (int i = 0; i < max; i++) {
        printf("%d ", union_set[i]);
    }

    printf("\n\nIntersection of Set A and B: ");
    set_intersection(BA, BB, intersection);
    for (int i = 0; i < max; i++) {
        printf("%d ", intersection[i]);
    }

    printf("\n\nSet Difference (A-B): ");
    set_difference(BA,BB);

    printf("\n\nSet Difference (B-A): ");
    set_difference(BB,BA);
   
    
    


}