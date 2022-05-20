#include <iostream>

using namespace std;
void reversearray(int aa [], int start, int endd){

    while(start<endd)
    {

        int temp = aa[start];
        aa[start]=aa[endd];
        aa[endd]=temp;
        start++;
        endd--;
    }
}

void printarray (int aa[],int s)
{

    for(int i=0;i<s;i++)
    {
        cout<<aa[i]<<endl;
    }
}

int main()
{
    int aa[]={1,2,3,4,5,6,7,9};
    int n = sizeof(aa) / sizeof(aa[0]);
     printarray(aa,n);
    reversearray(aa,0,n-1);
    cout<<"enter revrese array"<<endl;
     printarray(aa,n);
    return 0;
}
