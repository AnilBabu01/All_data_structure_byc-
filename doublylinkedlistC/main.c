#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    struct node *next;
    struct node *prev;
    int info;
};

void createlist(struct node **head,struct node **tail)
{
    int data;
    struct node *newnode;
    struct node *temp;

    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->next=NULL;

        temp=*head;


    printf("\nenter element you want to insert:");
    scanf("%d",&data);

    if(temp==NULL)
    {
       *head=*tail=newnode;
       newnode->info=data;

               printf("\nsuccessfully inserted %d as first element...",newnode->info);
    }

    else
    {
        newnode->info=data;
        newnode->next=*head;

        temp->prev=newnode;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=newnode;
        newnode->prev=temp;
        *tail=newnode;

        printf("\nsuccessfully inserted %d element...",newnode->info);

    }
}

void display_forward(struct node **head)
{
    struct node *temp;
    temp=*head;
    while(temp->next!=*head)
    {
        printf("\t%d",temp->info);
        temp=temp->next;
    }
    printf("\t%d",temp->info);
}

void display_backward(struct node **tail)
{
     struct node *temp;
    temp=*tail;
    while(temp->prev!=*tail)
    {
        printf("\t%d",temp->info);
        temp=temp->prev;
    }
    printf("\t%d",temp->info);
}

void main()
{
    struct node *head;
    struct node *tail;
    int choice;

    head=tail=NULL;

    while(1)
    {

        printf("\n\n enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1: createlist(&head,&tail);
                break;

        case 2: display_forward(&head);
                 break;

        case 3: display_backward(&tail);
                break;

        case 4: exit(1);

        default: printf("\n enter valid choice...");
        }
    }
}
