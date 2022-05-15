#include <iostream>
#define n 100
using namespace std;

class queuee{

  int *arr;
  int frontt;
  int backk;
  public:
      queuee()
      {
          arr = new int[n];
          frontt=-1;
          backk=-1;
      }

 int countt(int *arr)
 {
     int c=0;
     for(int i =0;i<n;i++)
     {
         if(arr[i]!=0)
         {
             c++;
             cout<<arr[i];

         }
     }
     return c;
 }
     void enqueueAtbeg(int val)
     {
         if(frontt==0&& backk==n-1 || backk==n-1)
         {
             cout<<"The queue is full"<<endl;
             return;
         }
         else if(frontt==-1)
         {
             frontt=0;
             backk=0;
             arr[backk]=val;
         }
         else if(backk!=n-1)
         {
             int c=0;
             c = countt(arr);
            int k=backk+1;
             for(int i=1;i<=c;i++)
             {
                 arr[k]=arr[k-1];
                 k--;
             }

             arr[k]=val;
             frontt=k;
             backk+1;

         }
         else
         {
             frontt--;
             arr[frontt]=val;
         }

     }

     void enqueueAtend(int val)
     {
         if(frontt==0&& backk==n-1 || backk==n+1)
         {
             cout<<"The queue is full"<<" ";
             return;
         }
         else if(frontt==-1)
         {
             frontt=backk=0;
             arr[backk]=val;
         }
         else if(frontt!=0 && backk==n-1)
         {


            int k=frontt-1;
             for(int i=frontt;i<=backk;i++)
             {
                 arr[k]=arr[i];
                 k++;
             }
                   frontt--;
                   arr[backk]=val;

         }
         else
         {
             backk--;
             arr[backk]=val;
         }

     }

     void dequeue()
     {
         if(frontt==-1)
         {
             cout<<"queue is empty"<<endl;
             return;
         }
         else
         {
             int val = arr[frontt];
             if(frontt==backk)
             {
                 frontt=backk=-1;
             }
             else if(frontt==n-1)
             {
                 frontt=0;
             }
             else
             {
                 frontt++;
             }
             cout<<"deleted item is "<<val<<endl;
         }

     }

    void peek()
     {
         if(frontt==-1)
         {
             cout<<"The queue is empty"<<endl;
             return;
         }
         else
         {
             int val = arr[frontt];
             cout<<"Peek item is "<<val<<endl;
         }
     }

     void display()
     {
        if(frontt==-1)
        {
            cout<<"The queue is empty"<<endl;
        }
        else
        {
             for(int i=frontt;i<=backk;i++ )
             {
                 cout<<arr[i]<<" ";
             }
             cout<<endl;
        }

     }

     void menu ()
     {
         cout<<"Enter the 1 for enqueueAtBeg "<<endl;
         cout<<"Enter the 2 for dequeue "<<endl;
         cout<<"Enter the 3 for peek "<<endl;
         cout<<"Enter the 4 for display "<<endl;
         cout<<"Enter the 5 for exit "<<endl;
         cout<<"Enter the 6 for enqueueAtEnd"<<endl;
     }

};
int main()
{
     int choice,val;
     queuee DoubleEndedQuueue;
     while(1)
     {
         DoubleEndedQuueue.menu();
         cin>>choice;
         switch(choice)
         {
         case 1:
             cout<<"Enter the enqueue"<<endl;
             cin>>val;
            DoubleEndedQuueue.enqueueAtbeg(val);
            break;
         case 2:
            DoubleEndedQuueue.dequeue();
            break;
         case 3:
            DoubleEndedQuueue.peek();
            break;
         case 4:
            DoubleEndedQuueue.display();
            break;
         case 5:
            break;
         case 6:
             cout<<"Enter the value for enqueue"<<endl;
             cin>>val;
            DoubleEndedQuueue.enqueueAtend(val);
         default:
            cout<<"Please enter the right choice"<<endl;
         }
     }
    return 0;
}
