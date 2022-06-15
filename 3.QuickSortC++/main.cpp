#include <iostream>

using namespace std;

void swapp(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partitionn(int arr[],int left,int right)
{
     int  pivot =arr[right];
     int i=left-1;
     for(int j=left;j<right;j++)
     {
         if(arr[j]<pivot)
         {
             i++;
             swapp(arr,i,j);
         }
     }
     swapp(arr,i+1,right);
     return i+1;

}

void Quicksort(int arr[],int left ,int right)
{

    if(left<right)
    {
        int pi = partitionn(arr,left,right);
         Quicksort(arr,left,pi-1);
         Quicksort(arr,pi+1,right);
    }
}

void printarray(int arr[],int s)
{
    for(int i=0;i<s;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main(){
   int arr[100],s;
   cout<<"Enter the size of array"<<endl;
   cin>>s;
   for(int i=0;i<s;i++)
   {
       cin>>arr[i];
   }
   cout<<"Before sorting"<<endl;
   printarray(arr,s);
   Quicksort(arr,0,s-1);
   cout<<"After sorting "<<endl;
   printarray(arr,s);

    return 0;
}


