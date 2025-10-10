#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;
void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
void main()
{
    int ch=0;
    while(ch!=9){
        printf("Choose one from the following...");
        printf("1.Insert at beginning\n2.Insert at the end\n3.Insert at random location\n4.Delete from beginning\n5.Delete from end\n6.Delete from a random location\n7.Display\n8.Display\n9Exit\nEnter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:beginsert();
                    break;
            case 2:lastinsert();
                    break;
            case 3:randominsert();
                    break;
            case 4:begin_delete();
                    break;
            case 5:last_delete();
                    break;
            case 6:random_delete();
                    break;
            case 7:Display();
                    break;
            case 8:Search();
                    break;
            case 9:exit(0);
                    break;
            default("Invalid choice!!!");
        }
    }
}

void beginsert()
{
    struct node *ptr;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node*));
    if(ptr==NULL)
    {
        printf("OVERFLOW");
    }
    else{
        printf("Enter item value :");
        scanf("%d",&item);
        if(head=NULL)
        {
            ptr->next=NULL;
            ptr->prev=NULL;
            ptr->data=item;
            head=ptr;
        }
        else{
            ptr->data=item;
            ptr->prev=NULL;
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
        }
        printf("\nNode inserted ");

    }
}
void lastinsert()
{
    struct node *ptr,*temp;
    int item;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        ptintf("\nOVERFLOW\n");
    }
    else{
        printf("\nEnter value :");
        scanf("%d",&item);
        ptr->data=item;
        if(head=NULL){
            ptr->next=NULL;
            ptr->prev=NULL;
            head=ptr;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp->next;
            }
            temp->next=ptr;
            ptr->prev=temp;
            ptr->next=NULL;
        }
    }
    Prinf("Node inserted ");
}
void randominsert()
{
    struct node *ptr,*temp;
    int item,loc,i;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("\nOVERFLOW");
    }
    else{
        temp=head;
        printf("Enter the location :");
        scanf("%d",&loc);
        for(i=0;i<loc;i++)
        {
            temp->next;
            if(temp==NULL){
                printf("\nThere are less than %d elementd",loc);
                return;
            }
        }
        printf("Enter value :");
        scanf("%d",&item);
        ptr->data=item;
        ptr->next=temp->next;
        ptr->prev=temp;
        temp->next=ptr;
        temp->next->prev=ptr;
        printf("\nNode inserted");
    }
}
void begin_delete()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nUNDERFLOW");

    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
        printf("\nNode deleted");
    }
    else{
        ptr=head;
        head=head->next;
        head->prev=NULL;
        free(ptr);
        printf("\nNode deleted");
    }
}
void last_delete()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
        printf("\nNode deleted\n");
    }
    else{
        ptr=head;
        if(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->prev->next=NULL;
        free(ptr);
        printf("\nNode deleted\n");
    }
}
void random_delete()
{
    struct node *ptr,*temp;
    int val;
    printf("\nEnter the the data after which the node is to be deleted :");
    scanf("%d",&val);
    ptr=head;
    while(ptr->data!=val)
    ptr=ptr->next;
    if(ptr->next==NULL)
    {
        printf("\nCan't delete\n");
    }
    else if(ptr->next->next==NULL)
    {
        ptr->next=NULL;
    }
    else{
        temp=ptr->next;
        ptr->next=temp->next;
        temp->next->prev=ptr;
        free(temp);
        printf("\nNode deleted\n");

    }
}
void display()
{
    struct node *ptr;
    printf("\nPrinting values...\n");
    ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void search()
{
    struct node *ptr;
    int item,flag,i=0;
    ptr=head;
    if(ptr==NULL){
        printf("\nEmpty list\n");
    }
    else{
        printf("\nEnter item which you want to search\n");
        scanf("%d",&item);
        while(ptr!=NULL)
        {
            if(ptr->data==item)
            {
                printf("\nItem found at location %d",i+1);
                flag=0;
                break;
            }
            else{
                flag=1;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag==1){
            printf("\nItem not found");
        }
    }
}