#include <iostream>

using namespace std;

void mergee(int arr[],int left ,int mid ,int right)
{
     int n1=mid-left+1;
     int n2=right-mid;
     int a[n1];
     int b[n2];
     for(int i=0;i<n1;i++)
     {
         a[i]=arr[i+left];
     }
     for(int j=0;j<n2;j++)
     {
         b[j]=arr[j+mid+1];
     }
     int i=0;
     int j=0;
     int k=left;
     while(i<n1&&j<n2)
     {
         if(a[i]<b[j])
         {
             arr[k]=a[i];
             k++;
             i++;
         }else
         {
             arr[k]=b[j];
             k++;
             j++;
         }
     }
     while(i<n1)
     {
         arr[k]=a[i];
         k++;
         i++;
     }

     while(j<n2)
     {
         arr[k]=b[j];
         k++;
         j++;
     }

}

void mergeSort(int arr[],int left ,int right)
{

    if(left<right)
    {
         int mid=(left+right)/2;
         mergeSort(arr,left,mid);
         mergeSort(arr,mid+1,right);
         mergee(arr,left,mid,right);
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
   mergeSort(arr,0,s-1);
   cout<<"After sorting "<<endl;
   printarray(arr,s);

    return 0;
}
