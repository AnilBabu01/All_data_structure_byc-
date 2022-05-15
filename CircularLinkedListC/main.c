#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void createlist(struct node **head)
{
    int data;
    struct node *newnode;
    struct node *temp;

    newnode=(struct node *)malloc(sizeof(struct node));

    printf("\n enter element you want to insert:");
    scanf("%d",&data);

    newnode->info=data;
    temp=*head;
    if(*head==NULL)
    {
        *head=newnode;
        newnode->next=*head;

        printf("\n successfully inserted %d element as first element...",newnode->info);
    }

    else
    {
        while(temp->next!=*head)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;

         printf("\n successfully inserted %d element...",newnode->info);
    }
}

void insert_beg(struct node **head)
{
        int data;
    struct node *newnode;
    struct node *temp;

    newnode=(struct node *)malloc(sizeof(struct node));

    printf("\n enter element you want to insert:");
    scanf("%d",&data);

    newnode->info=data;
    temp=*head;
    if(*head==NULL)
    {
        *head=newnode;
        newnode->next=*head;

        printf("\n successfully inserted %d element as first element...",newnode->info);
    }

    else
    {
        temp=*head;
        while(temp->next!=*head)
        {
            temp=temp->next;
        }
        temp->next=newnode;

        newnode->next=*head;
        *head=newnode;

         printf("\n successfully inserted %d element at beginning...",newnode->info);
    }
}

void insert_end(struct node **head)
{
     int data;
    struct node *newnode;
    struct node *temp;

    newnode=(struct node *)malloc(sizeof(struct node));

    printf("\n enter element you want to insert:");
    scanf("%d",&data);

    newnode->info=data;

    if(*head==NULL)
    {
        *head=newnode;
        newnode->next=*head;

        printf("\n successfully inserted %d element as first element...",newnode->info);
    }

    else
    {
        temp=*head;
        while(temp->next!=*head)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;

        printf("\n successfully inserted %d element at end...",newnode->info);
    }
}

void insert_after(struct node **head)
{
    int after;
     int data;
     struct node *current;
     struct node *newnode;
     printf("\nenter element after which you want to insert:");
     scanf("%d",&after);
     if(*head==NULL)
    {
        printf("\nlist is empty..");
    }

    else
    {
        current=*head;
        while(current->info!=after && current->next!=*head)
        {
            current=current->next;
        }

        if(current->next==*head)
        {
            printf("\nlist is ended and %d not found so insertion not possible...",after);
        }

        else
        {
             printf("\nenter element you want to insert:");
             scanf("%d",&data);

             newnode=(struct node *)malloc(sizeof(struct node));
             newnode->next=current->next;
             current->next=newnode;
             newnode->info=data;

              printf("\nsuccessfully inserted %d in list after %d...",newnode->info,after);

        }
    }
}

void insert_before(struct node **head)
{
   int before;
     int data;
     struct node *current;
     struct node *temp;
     struct node *newnode;
     printf("\nenter element before which you want to insert:");
     scanf("%d",&before);
     if(*head==NULL)
    {
        printf("\nlist is empty..");
    }

    else
    {
        current=temp=*head;
        while(current->info!=before&& current->next!=*head)
        {
            temp=temp->next;
            current=temp->next;
        }

        if(temp->next==*head)
        {
            printf("\nlist is ended and %d not found so insertion not possible...",before);
        }

        else
        {
             printf("\nenter element you want to insert:");
             scanf("%d",&data);

             newnode=(struct node *)malloc(sizeof(struct node));
             newnode->next=temp->next;
             temp->next=newnode;
             newnode->info=data;

              printf("\nsuccessfully inserted %d in list before %d...",newnode->info,before);

        }
    }

}

void delete_beg(struct node **head)
{
    struct node *temp;
    struct node *current;

    if(*head==NULL)
     {
         printf("\n list is empty so deletion not possible..");
     }

     else
     {

         temp=current=*head;
         while(current->next!=*head)
         {
             current=current->next;
         }
         if(temp==current)
         {
           printf("\n successfully deleted only element %d of list so now list is empty...",temp->info);
           free(temp);
           *head=NULL;
         }

         else
         {
         current->next=temp->next;
         *head=temp->next;

         printf("\n successfully deleted %d element from beginning...",temp->info);

         free(temp);
         }
     }
}

void delete_end(struct node **head)
{
    struct node *temp;
    struct node *current;

    if(*head==NULL)
     {
         printf("\n list is empty so deletion not possible..");
     }

     else
     {

         temp=current=*head;
         while(current->next!=*head)
         {
             temp=temp->next;
             current=temp->next;
         }

         if(temp==current)
         {
           printf("\n successfully deleted only element %d of list so now list is empty...",current->info);
           free(current);
           *head=NULL;
         }

         else
         {
             temp->next=current->next;
             printf("\n successfully deleted %d element from end...",current->info);
             free(current);
         }
     }
}

void delete_after(struct node **head)
{
    struct node *current;
     struct node *temp;
     int after;
     printf("\nenter element after which you want to delete:");
     scanf("%d",&after);
     if(*head==NULL)
    {
        printf("\nlist is empty..");
    }

    else
    {
        current=temp=*head;
        while(temp->info!=after && temp->next!=*head)
        {
            temp=temp->next;
            current=temp->next;
        }

        if(current==*head)
        {
            printf("\nlist is ended and %d not found so deletion not possible...",after);
        }

        else
        {
            temp->next=current->next;
             printf("\nsuccessfully delete %d after %d from list...",current->info,after);
            free(current);
        }
    }
}



void display(struct node **head)
{
    struct node *temp;
    if(*head==NULL)
    {
        printf("\nlist is empty...");
    }

    else
    {
    temp=*head;
    while(temp->next!=*head)
    {
        printf("\t%d",temp->info);
        temp=temp->next;
    }
    printf("\t%d",temp->info);
    }
}

void main()
{
    int choice;
    struct node *head;

    head=NULL;

    while(1)
    {
        printf("\n\n enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: createlist(&head);
                    break;

            case 2: insert_beg(&head);
                    break;

            case 3: insert_end(&head);
                    break;

            case 4: insert_after(&head);
                    break;

            case 5: insert_before(&head);
                    break;

            case 6: delete_beg(&head);
                    break;

            case 7: delete_end(&head);
                    break;

            case 8: delete_after(&head);
                    break;

            case 9: display(&head);
                    break;

            case 10: exit(1);

            default: printf("enter valid choice....");
        }
    }

}
