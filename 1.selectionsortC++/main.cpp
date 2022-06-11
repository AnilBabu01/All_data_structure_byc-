#include <iostream>

using namespace std;

void bubble_sort(int a[], int s)
{
     for(int i=0;i<s-1;i++)
     {
         for(int j=0;j<s;j++)
         {
             if(a[j]>a[j+1])
             {
                 int temp =a[j];
                 a[j]=a[j+1];
                 a[j+1]=temp;
             }
         }
     }

}

void print_array(int a[],int s)
{
        for(int i=0;i<s;i++)
    {
        cout<<a[i]<<endl;
    }
}
int main()
{


    int arr[100],s;
    cout<<"Enter the size of array "<<endl;
    cin>>s;
    for(int i=0;i<s;i++)
    {
        cin>>arr[i];
    }
    bubble_sort(arr,s);

     cout<<"After bubble sorting "<<endl;

     print_array(arr,s);
    return 0;
}
