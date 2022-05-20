#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

void menu()
{
    printf("\n\n  press 1 as choice for inserting first element..");
    printf("\n press 2 as choice for inserting element at beginning..");
    printf("\n press 3 as choice for inserting element at end..");
    printf("\n press 4 as choice for inserting element after specific element..");
    printf("\n press 5 as choice for inserting element before specific element..");
     printf("\n press 6 as choice for deleting element from beginning..");
     printf("\n press 7 as choice for deleting element from end..");
     printf("\n press 8 as choice for deleting element after specific element..");
     printf("\n press 9 as choice for deleting element before specific element..");
     printf("\n press 10 as choice for finding number of nodes in list..");
      printf("\n press 11 as choice for reverse the list..");
    printf("\n press 12 as choice for displaying element in list..");
    printf("\n press 13 as choice for exit..");
}

void createlist(struct node**start)
{
    int d;
    struct node *temp;
    struct node *newnode;
    printf("\nenter element you want to insert:");
    scanf("%d",&d);
    newnode=(struct node *)malloc(sizeof(struct node));

        *start=newnode;
        newnode->info=d;
        newnode->next=NULL;

         printf("\nsuccessfully inserted %d as first element in list...",newnode->info);

}

void display(struct node **start)
{
    struct node *current;
    if(*start==NULL)
    {
        printf("\nlist is empty..");
    }

    else
    {
        current=(*start);
        while(current!=NULL)
        {
            printf("\t%d",current->info);
            current=current->next;
        }
    }
}

void insert_beg(struct node**start)
{
    int d;
    struct node *newnode;
     newnode=(struct node *)malloc(sizeof(struct node));

     printf("\nenter element you want to insert:");
    scanf("%d",&d);

    if(*start==NULL)
    {
        *start=newnode;
        newnode->info=d;
        newnode->next=NULL;

         printf("\nsuccessfully inserted %d as first element in list...",newnode->info);
    }

    else
    {
        newnode->next=*start;
        *start=newnode;
        newnode->info=d;

         printf("\nsuccessfully inserted %d in list...",newnode->info);




    }

}

void insert_end(struct node **start)
{
     int d;
    struct node *newnode;
    struct node *temp;
     newnode=(struct node *)malloc(sizeof(struct node));

     printf("\nenter element you want to insert:");
    scanf("%d",&d);

    if(*start==NULL)
    {
        *start=newnode;
        newnode->info=d;
        newnode->next=NULL;

         printf("\nsuccessfully inserted %d as first element in list...",newnode->info);
    }

    else
    {
        temp=*start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->info=d;

        printf("successfully inserted %d in list..",newnode->info);
    }
}

 void insert_after(struct node**start)
 {
     int after;
     int d;
     struct node *current;
     struct node *newnode;
     printf("\nenter element after which you want to insert:");
     scanf("%d",&after);
     if(*start==NULL)
    {
        printf("\nlist is empty..");
    }

    else
    {
        current=*start;
        while(current->info!=after && current!=NULL)
        {
            current=current->next;
        }

        if(current==NULL)
        {
            printf("\nlist is ended and %d not found so insertion not possible...",after);
        }

        else
        {
             printf("\nenter element you want to insert:");
             scanf("%d",&d);

             newnode=(struct node *)malloc(sizeof(struct node));
             newnode->next=current->next;
             current->next=newnode;
             newnode->info=d;

              printf("\nsuccessfully inserted %d in list...",newnode->info);

        }
    }

 }

 void insert_before(struct node **start)
 {
    int before;
     int d;
     struct node *current;
     struct node *prev;
     struct node *newnode;
     printf("\nenter element before which you want to insert:");
     scanf("%d",&before);

          if(*start==NULL)
          {
            printf("\nlist is empty..");
          }

          else
          {
              current=prev=*start;
            while(current->info!=before && current!=NULL)
            {
                prev=current;
            current=current->next;
            }

            if(current==NULL )
            {
                      printf("\nlist is ended and %d not found so insertion not possible...",before);
            }

            else
            {
             printf("\nenter element you want to insert:");
             scanf("%d",&d);

             newnode=(struct node *)malloc(sizeof(struct node));
             newnode->next=current;
             prev->next=newnode;
              newnode->info=d;

              printf("\nsuccessfully inserted %d in list...",newnode->info);


            }

          }

 }

 void delete_beg(struct node **start)
 {
     struct node *temp;
     if(*start==NULL)
     {
         printf("\n list is empty so deletion not possible..");
     }

     else
     {
         temp=*start;
         *start=temp->next;
        printf("\n successfully deleted %d element from list from beginning..",temp->info);
         free(temp);

     }
 }

 void delete_end(struct node **start)
 {
     struct node *current;
     struct node *prev;

      if(*start==NULL)
      {
         printf("\n list is empty so deletion not possible..");
      }

     else
     {
         current=prev=*start;

        while(current->next!=NULL)
        {
          prev=current;
          current=current->next;
        }
         prev->next=current->next;
         printf("\n successfully deleted %d element from list from end..",current->info);
         free(current);
     }

 }

 void delete_after(struct node **start)
 {
     struct node *current;
     struct node *temp;
     int after;
     printf("\nenter element after which you want to delete:");
     scanf("%d",&after);
     if(*start==NULL)
    {
        printf("\nlist is empty..");
    }

    else
    {
        current=temp=*start;
        while(current->info!=after && temp->next!=NULL)
        {
            current->next=temp;
            temp=temp->next;

        }

        if(temp==NULL)
        {
            printf("\nlist is ended and %d not found so deletion not possible...",after);
        }

        else
        {
            current->next=temp->next;

              printf("\nsuccessfully delete %d in list...",temp->info);
              free(temp);

        }
    }

 }

 void delete_before(struct node **start)
 {
     struct node *current;
     struct node *prev;
     struct node *temp;
     int before;
     printf("\nenter element before which you want to delete:");
     scanf("%d",&before);
     if(*start==NULL)
    {
        printf("\nlist is empty..");
    }

    else
    {
        current=prev=*start;
        while(current->info!=before && current->next!=NULL)
        {
            temp=prev;
            prev=current;
            current=current->next;

        }

        if(current->next==NULL)
        {
            printf("\nlist is ended and %d not found so deletion not possible...",before);
        }

        else
        {
            temp->next=prev->next;
            printf("\nsuccessfully delete %d in list...",prev->info);
            free(prev);
        }

    }
 }

 void list_length(struct node **start)
 {
     int count=0;
     struct node *temp;
     temp=*start;

     while(temp!=NULL)
     {
         count++;
         temp=temp->next;
     }

     printf("\n\nnumber of nodes in list is %d...",count);
 }

 void reverse_list(struct node **start)
 {
    struct node *current,*prev,*nextnode;

    prev=NULL;
    current=nextnode=*start;

    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    *start=prev;
 }

void main()
{
    int choice;
    int item;
    struct node *start=NULL;

    while(1)
    {
        menu();

         printf("\n\nenter your choice:");
         scanf("%d",&choice);

         switch(choice)
         {
           case 1: createlist(&start);
                   break;

           case 2: insert_beg(&start);
                   break;

           case 3: insert_end(&start);
                   break;

            case 4: insert_after(&start);
                    break;

            case 5: insert_before(&start);
                    break;

            case 6: delete_beg(&start);
                    break;

            case 7: delete_end(&start);
                    break;

            case 8: delete_after(&start);
                    break;

            case 9: delete_before(&start);
                    break;

            case 10:list_length(&start);
                    break;

            case 11: reverse_list(&start);
                     break;

           case 12: display(&start);
                   break;

           case 13: exit(1);
                   break;

           default:
                   printf("\n enter valid choice..");
                   break;
         }
    }


}
