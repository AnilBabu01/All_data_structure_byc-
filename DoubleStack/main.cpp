#include <iostream>
#define n 100
using namespace std;

class stackk{

int *arr;
int top1,top2;
public:
    stackk()
    {
        arr=new int[n];
        top1=-1;
        top2=n-1;
    }

    void pushLeftStack(int x)
    {
        if(top1==top2)
        {
            cout<<"The stack is overflow"<<endl;
            return;
        }
        else
        {
            top1++;
            arr[top1]=x;
        }
    }
    void pushRightStack(int x)
    {
        if(top1==top2)
        {
            cout<<"The stack is overflow"<<endl;
            return;
        }
        else
        {
            top2--;
            arr[top2]=x;
        }
    }
    void popLeftStack()
    {

        if(top1==-1)
        {
            cout<<"The stack is underflow"<<endl;
            return;
        }
        else
        {
           int value = arr[top1];
           top1--;
           cout<<"The poped item this is"<<value<<endl;
        }
    }

     void popRighttStack()
    {

        if(top2==-n)
        {
            cout<<"The stack is underflow"<<endl;
            return;
        }
        else
        {
           int value = arr[top2];
           top2++;
           cout<<"The poped item this is"<<value<<endl;
        }
    }

    void toppLeftStack()
    {
        if(top1==-1)
        {
            cout<<"The is stack is Underflow"<<endl;
        }
        else
        {

            int value = arr[top1];
            cout<<"The top value is "<<value<<endl;

        }
    }

    void toppRightStack()
    {
        if(top2==n)
        {
            cout<<"The is stack is Underflow"<<endl;
        }
        else
        {

            int value = arr[top2];
            cout<<"The top value is "<<value<<endl;

        }
    }

    void  displayLeftStack()
    {
        if(top1==-1)
        {
            cout<<"The stack is empty"<<endl;
        }
        else
        {
            for(int i=0;i<=top1;i++)
            {

                cout<<arr[i]<<endl;
            }
        }
    }
    void  displayRightStack()
    {
        if(top2==n)
        {
            cout<<"The stack is empty"<<endl;
        }
        else
        {
            for(int i=top2;i<n-1;i++)
            {

                cout<<arr[i]<<endl;
            }
        }
    }

    void menu()
    {
        cout<<"Enter the 1 for push from left stack"<<endl;
        cout<<"Enter the 2 for pop from left stack"<<endl;
        cout<<"Enter the 3 for push from right stack"<<endl;
        cout<<"Enter the 4 for pop from right stack"<<endl;
        cout<<"Enter the 5 for peek from left stack"<<endl;
        cout<<"Enter the 6 for peek from right stack"<<endl;
        cout<<"Enter the 7 for display left stack"<<endl;
        cout<<"Enter the 8 for display right stack"<<endl;
        cout<<"Enter the 9 for exit"<<endl;
    }
};

int main()
{
    stackk st;
    int choice,val;
    while(1)
    {

        st.menu();
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the value for push left stack"<<endl;
            cin>>val;
            st.pushLeftStack(val);
            break;
        case 2:
            st.popLeftStack();
            break;
        case 3:
            cout<<"Enter the value for push left stack"<<endl;
            cin>>val;
            st.pushRightStack(val);
            break;
        case 4:
            st.popRighttStack();
            break;
        case 5:
            st.toppLeftStack();
            break;
        case 6:
            st.toppRightStack();
            break;
        case 7:
            st.displayLeftStack();
            break;
        case 8:
            st.displayRightStack();
            break;
        case 9:
            break;

        default:
            cout<<"Please enter the right choice"<<endl;

        }
    }


    return 0;
}
