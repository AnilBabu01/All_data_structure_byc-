#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef struct
{
    int order;
    int prioty;
    int value[max];
}Data;
typedef struct {
  int front;
  int rear;
   Data d[max];

}pqueue;
typedef enum{false,true}boolean;

boolean isEmpty(pqueue *pq)
{
    if(pq->front==-1)
    {
        return true;
    }
    else
    {
      return false;
    }

}

boolean isFull(pqueue *pq)
{
    if(pq->front==0&&pq->rear==max-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void pqueue_init(pqueue *pq)
{
    int i;
    pq->front=-1;
    pq->rear-1;

    for(i=0;i<max;i++)
    {
        pq->d[i].order=0;
        pq->d[i].prioty=0;
        pq->d[i].value[i]==0;
    }
}

void pqenqueue(pqueue *pq,Data dt)
{


    Data temp;
    int i,j;
    if(isFull(pq))
    {
        printf("\nOverflow");
    }
    else
    {
        pq->rear++;
        pq->d[pq->rear]=dt;

        if(pq->front==1)
        {
            pq->front=0;
        }
        else
        {
            for(i=pq->front;i<=pq->rear;i++)
            {

                for(j=i+1;j<=pq->rear;j++)
                {

                    if(pq->d[i].prioty>pq->d[j].prioty)
                    {
                        temp=pq->d[i];
                        pq->d[i]=pq->d[j];
                        pq->d[j]=temp;
                    }
                    else
                    {
                        if(pq->d[i].prioty==pq->d[j].prioty)
                        {

                            if(pq->d[i].order>pq->d[j].order)
                            {
                                temp=pq->d[i];
                                pq->d[i]=pq->d[j];
                                pq->d[j]=temp;
                            }


                        }


                    }

                }

            }
        }

    }

}


Data pqdequeue(pqueue *pq)
{
   Data t;
   t.order=0;
   t.prioty=0;
   t.value[0]=0;
   if(isEmpty(&pq))
   {
       printf("\npqueue is Overflow");
        return t;
   }
    else
    {
        t=pq->d[pq->front];
         if(pq->front==pq->rear)
         {
             pq->front=-1;
             pq->rear=-1;
         }
         else
         {
             pq->front++;
             printf("\n delete item is");
             printf("\n item = %d ",t.value[pq->front-1]);
             printf("\n priority = %d ",t.prioty);
             printf("\n order = %d ",t.order);

         }
    }


}

void Display(pqueue *pq)
{
    int i;
       if(isEmpty(pq))
       {
           printf("\n Overflow");
       }
       else
       {
           for(i=pq->front;i<-pq->rear;i++)
           {
                printf("\n delete item is");
                printf("\n item = %d ",pq->d[i].value[i]);
                printf("\n priority = %d ",pq->d[i].prioty);
                printf("\n order = %d ",pq->d[i].order);
           }

       }

}

void menu()
{
    printf("\nenter the 1 for enqueue in pq");
    printf("\nenter the 2 for dequeue in pq");
    printf("\nenter the 3 for display in pq");
    printf("\nenter the 4 for exit in pq");
}

void perpor( pqueue *pq ,Data d)
{

         int i,n;
          printf("\n enter no of item");
           scanf("%d",&n);
        for(i=0;i<n;i++)
          {
          printf("\nenter the item");
            scanf("%d",&d.value[i]);
          printf("\nenter the priority");
            scanf("%d",&d.prioty);
          printf("\nenter the order");
            scanf("%d",&d.order);
            pqenqueue(&pq,d);
           }
}


int main()
{
    pqueue *pq;
    int choice,item,n,i;
     Data d;

    pqueue_init(&pq);

     while(1)
     {
          menu();
        printf("\nenter your choice");
           scanf("%d",&choice);


        switch(choice)
        {
         case 1:
             perpor(&pq,d);

             break;
         case 2:
            pqdequeue(&pq);
            break;
         case 3:
            Display(&pq);
            break;
         case 4:
            exit(0);
            break;
         default:
            printf("\nenter the right ");




        }

     }

    printf("Hello world!\n");
    return 0;
}
