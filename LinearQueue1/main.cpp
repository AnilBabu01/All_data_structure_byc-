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

     void enqueue(int val)
     {
         if(backk==n-1)
         {
             cout<<"The queue is full"<<endl;
             return;
         }
         else if(frontt==-1)
         {
             frontt=backk=0;
         }
         else if(frontt!=0&&backk==n-1)
        {
            for(int i=frontt;i<=backk;i++)
            {
                arr[i-frontt]=arr[i];
                backk=backk-frontt+1;
                frontt=0;
            }

         }
         else
         {
             backk++;
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
             cout<<"Peel item is "<<endl;
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
             for(int i=frontt;i<backk;i++ )
             {
                 cout<<arr[frontt+i]<<endl;
             }
        }

     }

     void menu ()
     {
         cout<<"Enter the 1 for enqueue "<<endl;
         cout<<"Enter the 2 for dequeue "<<endl;
         cout<<"Enter the 3 for peek "<<endl;
         cout<<"Enter the 4 for display "<<endl;
         cout<<"Enter the 1 for exit "<<endl;
     }

};
int main()
{
     int choice,val;
     queuee linearquueue;
     while(1)
     {
         linearquueue.menu();
         cin>>choice;
         switch(choice)
         {
         case 1:
             cout<<"Enter the enqueue"<<endl;
             cin>>val;
            linearquueue.enqueue(val);
            break;
         case 2:
            linearquueue.dequeue();
            break;
         case 3:
            linearquueue.peek();
            break;
         case 4:
            linearquueue.display();
            break;
         case 5:
            break;
         default:
            cout<<"Please enter the right choice"<<endl;
         }
     }
    return 0;
}