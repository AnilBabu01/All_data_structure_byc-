#include <iostream>

using namespace std;

int main()
{

    int a[100],n,min,max;
    cout << "enter the size of array" << endl;
    cin>>n;
    cout<<"enter the elements of array"<<endl;
    for(int i=0;i<n;i++)
    {

        cin>>a[i];
    }
    min = max = a[0];

      for(int i =0 ;i<n ;i++)
      {

          if(a[i]>max)
          {

              max=a[i];
          }
          if(a[i]<min)
          {
              min=a[i];
          }
      }

      cout<<"maximum no is "<<max<<endl;
      cout<<"min no is "<<min<<endl;
    return 0;
}
