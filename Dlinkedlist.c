#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
    
}


void insert_at_beginning() {
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    struct Node *newNode = createNode(data);
    
    if (head == NULL) {
        head = newNode;
    }

else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

return;

}


void insert_at_end() {
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    }

    else {
        struct Node *temp = head;
        while ( temp->next != NULL) {
              temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }

}


void insert_position() {
    int data, pos, pos1 = 0;
    struct Node *temp = head;
    printf("Enter the position: ");
    scanf("%d",&pos);

    while (temp -> next) {
        pos1++;

        if (pos1 == pos) {
            break;
        }

        temp = temp->next;

    }

    printf("Enter the data: ");
    scanf("%d",&data);

    struct Node *newNode = createNode(data);
    

    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;

}

void delete_at_beginning() {

    struct Node *temp = head;

    if (temp == NULL) {
        printf("Empty");
    } else if(temp->next==NULL) {
        head = NULL;
        printf("Element deleted");
    }
    else {
        head = temp->next;
        temp->next->prev = NULL;
    }
}


void delete_at_end() {
    struct Node *temp = head;
    

    while (temp -> next ->next != NULL) {
        temp = temp -> next;          
    }

            temp -> next = NULL;

}


void delete_at_position() {
    int pos, pos1 = 0;
    struct Node *temp = head;
        struct Node *ptr = head;
                struct Node *ptr1 = head;


    printf("Enter the position: ");
    scanf("%d",&pos);

    while (temp -> next) {
        pos1++;

        if (pos1 == pos) {
            break;
        }

        temp = temp->next;
        ptr=temp->prev;
        ptr1=temp->next;

    }

    ptr -> next = temp -> next;
    ptr1 -> prev = temp -> prev;
    

    
}


void display() {
    struct Node *temp = head;

    while (temp!=NULL) {
        printf("%d\t",temp->data);
        temp = temp->next;
        
    }
}









void main() {
int ch,n;


do {
    printf("\n Enter the choice:\n 1.Insert at Beginning \n 2.Insert at end \n 3.Insert at position \n 4.Delete at Beginning \n 5.Delete at end \n 6. Delete at Position \n 7.Display\n ");
    scanf("%d",&ch);

    switch(ch) {

        case 1:
        insert_at_beginning();
        break;

        case 2:
        insert_at_end();
        break;

        case 3:
        insert_position();
        break;

        case 4:
        delete_at_beginning();
        break;

        case 5:
        delete_at_end();
        break;

        case 6:
        delete_at_position();
        break;


        case 7:
        display();
        break;

        case 8:
        break;

        default:
        printf("Enter a valid choice");
        break;


    }





} while (ch!=8);



}