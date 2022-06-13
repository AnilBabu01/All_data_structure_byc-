#include <iostream>

using namespace std;

void selection_sort(int a[], int s)
{
     for(int i=0;i<s-1;i++)
     {
         int smallest=i;
         for(int j=i+1;j<s;j++)
         {
             if(a[j]<a[smallest])
             {
                smallest=j;
             }
         }
         int temp =a[i];
         a[i]=a[smallest];
         a[smallest]=temp;
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
    selection_sort(arr,s);

    cout<<"After bubble sorting "<<endl;

    print_array(arr,s);
    return 0;
}
