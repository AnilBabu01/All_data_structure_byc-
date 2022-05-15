#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef struct
{
    int front,rear;
    int a[max];
}queue;
typedef enum{FALSE,TRUE}Boolean;


void menu()
{

    printf("\n\nenter 1 as choice for insertion at beg");
     printf("\n\nenter 2 as choice for insertion at end");
    printf("\nenter 3 as choice for deletion at beg");
     printf("\nenter 4 as choice for deletion at end");
    printf("\nenter 5 as choice for displaying top element of queue..");
     printf("\nenter 6 as choice for displaying end element of queue..");
    printf("\nenter 7 as choice for displaying elements of queue..");
    printf("\nenter 8 as choice for exit..");
}

   void createEmptyLQ(queue *lq)
   {
       lq->front=-1;
       lq->rear=-1;
   }

   Boolean isEmpty(queue *lq)
   {
       if(lq->front== -1)
       {
            return TRUE;
       }
       else
       {
           return FALSE;
       }
   }

   Boolean isFUll(queue *lq)
   {
       if(lq->front==0&&lq->rear==max-1)
       {
           return TRUE;
       }
       else
       {
           return FALSE;
       }
   }
 int coutt (int *arr)
 {
     int i,c=0;
       for(i=0;i<max;i++)
       {  if(arr[i]!=0)
       {
           c++;
       }
       }

       return c;
 }

 void enqueue_at_beg(queue *lq)
 {
     int i,k,c=0;
     int item;
      printf("\nenter the item to add");
        scanf("%d",&item);
     if(isFUll(lq))
     {
         printf("\n overflow");
     }
     else
     {
       if(isEmpty(lq))
     {
         lq->front=0;
         lq->rear=0;
         lq->a[lq->rear]=item;
     }
     else if(lq->rear!=max-1)
     {

        c=coutt(lq->a);

        printf("\n sizeo ques %d",c);
         k=lq->rear+1;
       for(i=1;i<c;i++)
         {
             lq->a[k]=lq->a[k-1];
             k--;
         }

         lq->a[k]=item;
         lq->front=k;
         lq->rear+1;
     }
     else
     {
         lq->front--;
         lq->a[lq->front]=item;
     }

     }

 }

 void enqueue_at_end(queue *lq)
 {
     int i,item,k;
      printf("\nenter the item to add at end");
           scanf("%d",&item);
     if(isFUll(lq))
     {
         printf("\noverflow");
     }
     else
     {
         if(isEmpty(lq))
         {
             lq->front=lq->rear=0;
             lq->a[lq->rear]=item;

         }
         else if((lq->front!=0)&&(lq->rear==max-1))
         {
             k=lq->front-1;

             for(i=lq->front;i<=lq->rear;i++)
             {
                 lq->a[k]=lq->a[i];
                 k++;
             }
             lq->front--;
             lq->a[lq->rear]=item;
         }
         else
         {
             lq->rear++;
             lq->a[lq->rear]=item;
         }
     }
 }

void dequeue_from_front (queue *lq)
{
          int item;
          if(isEmpty(lq))
          {
              printf("\noverflow");
              return 0;
          }
          else
          {
              item=lq->a[lq->front];
                if(lq->front==lq->rear)
                {
                    lq->rear=lq->front=-1;
                }
                else
                {
                    lq->front++;
                    printf("\ndeleted item is %d ",item);
                }
          }

}

void dequeue_from_rear(queue *lq)
{
     int item;
     if(isEmpty(lq))
     {
         printf("\nenderflow");
     }
     else
     {
         item=lq->a[lq->rear];
         if(lq->front==lq->rear)
         {
             lq->front=lq->rear=-1;
         }
         else
         {
             lq->rear--;
             printf("\nDelete item is %d ",item);
         }
     }
}


void peek_from_front(queue *lq)
{
    int item;
    if(isEmpty(lq))
    {
        printf("\n the queue is overflow \n ");
    }
    else
    {
        item=lq->a[lq->front];
        printf("the  peeked from front item is %d ",item);
    }
}

void peek_from_end(queue *lq)
{
     int item;
    if(isEmpty(lq))
    {
        printf("\n the queue is overflow \n ");
    }
    else
    {
        item=lq->a[lq->rear];
        printf("the  peeked from end item is %d ",item);
    }
}
void display(queue *lq)
{
    int i;
    if(isEmpty(lq))
    {
        printf("the queue is overflow \n ");
    }
    else
    {
        for(i=lq->front;i<=lq->rear;i++)
        {
            printf(" %d ",lq->a[i]);
        }


    }
}


int main()
{
     int a;
     queue lq;
   int choice=0;

      createEmptyLQ(&lq);
      printf("\n size is %d ",a);

      while(1)
       {
        menu();
        printf("\n\nenter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                enqueue_at_beg(&lq);
                   break;

            case 2:
                enqueue_at_end(&lq);
                   break;

            case 3:
                dequeue_from_front(&lq);
                   break;

            case 4:
                dequeue_from_rear(&lq);
                   break;

            case 5:
                peek_from_front(&lq);
                   break;
            case 6:
                peek_from_end(&lq);
                break;
            case 7:
                display(&lq);
                break;
            case 8:
                exit(0);
                break;
            default:
                    printf("\nenter valid choice... ");
                    break;
        }
    }
    return 0;
}



