#include <iostream>
#include<climits>
using namespace std;

int kadane(int aa[],int s)
{

    int cursum=0;
    int maxxsubarray1=0;
    for(int i=0;i<s;i++)
    {

        cursum=cursum+aa[i];
        if(cursum<0)
        {
            cursum=0;
        }
        if(cursum>maxxsubarray1)
        {
            maxxsubarray1=cursum;
        }

    }
    return maxxsubarray1;
}
int main()
{
    int a[100],n,sum=0;

    cout << "Enter the size of an array" << endl;
    cin>>n;
    cout<<"Enter elements of an array "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Here possible subarray"<<endl;
  for(int i=0;i<n;i++)
  {
        for(int j=i;j<n;j++)
       {
         for(int k=i;k<=j;k++)
          {
              cout<<a[k]<<" ";
          }
          cout<<endl;
      }
  }

int maxsub=0;

  for(int i=0;i<n;i++)
  {
        for(int j=i;j<n;j++)
       {
           sum=0;
         for(int k=i;k<=j;k++)
          {
             // cout<<a[k]<<" ";
             sum+=a[k];
          }
         // maxsub=max(maxsub,sum);
         if(sum>maxsub)
          {
              maxsub=sum;
          }
          }
      }

      cout<<"sum  of max subarrya "<<maxsub<<endl;

       for(int i=0;i<n;i++)
  {
        for(int j=i;j<n;j++)
       {
           sum=0;
         for(int k=i;k<=j;k++)
          {
             // cout<<a[k]<<" ";
             sum+=a[k];
          }
         // maxsub=max(maxsub,sum);
         if(sum<maxsub)
          {
              maxsub=sum;
          }
          }
      }

      cout<<"sum of min subarrya "<<maxsub<<endl;

      cout<<"cumulative approach"<<endl;

      int currentsubarray[n+1];
      currentsubarray[0]=0;
      for(int i=1;i<=n;i++)
      {

          currentsubarray[i]=currentsubarray[i-1]+a[i-1];
      }
      int maxSum=0;
      for(int i=1;i<=n;i++)
      {

          int sum=0;
          for(int j=0;j<i;j++)
          {
              sum=currentsubarray[i]-currentsubarray[j];
              if(sum>maxSum)
              {
                  maxSum=sum;
              }
          }
      }

      cout<<"max sum by cumulative approach "<<maxSum<<endl;

      cout<<"kadene's lagorithm"<<endl;

      int cursum =0;
      int maxSumdene =0;
      for(int i = 0;i<n;i++)
      {
          cursum+=a[i];
          if(cursum<0)
          {
              cursum=0;
          }
          if(cursum>maxSumdene)
          {
              maxSumdene=cursum;
          }
      }

      cout <<"max Sum of subarray is "<<maxSumdene<<endl;

      cout<<"max circular subarray sum "<<endl;
      int wrapsum;
      int nonrapsum;
      nonrapsum=kadane(a,n);
      int totalsum=0;
      for(int i =0;i<n;i++)
      {
          totalsum+=a[i];
          a[i]=-a[i];

      }
      wrapsum=totalsum+kadane(a,n);
      cout<<max(nonrapsum,wrapsum)<<endl;
      return 0;
  }



