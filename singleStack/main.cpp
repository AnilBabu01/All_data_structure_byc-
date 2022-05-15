#include <iostream>
#define n 100
using namespace std;

class stackk{

int *arr;
int top;
public:
    stackk()
    {
        arr=new int[n];
        top=-1;
    }

    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"The stack is overflow"<<endl;
            return;
        }
        else
        {
            top++;
            arr[top]=x;
        }
    }
    void pop()
    {

        if(top==-1)
        {
            cout<<"The stack is underflow"<<endl;
            return;
        }
        else
        {
           int value = arr[top];
           top--;
           cout<<"The poped item this is"<<value<<endl;
        }
    }

    void topp()
    {
        if(top==-1)
        {
            cout<<"The is stack is Underflow"<<endl;
        }
        else
        {

            int value = arr[top];
            cout<<"The top value is "<<value<<endl;

        }
    }

    void  display()
    {
        if(top==-1)
        {
            cout<<"The stack is empty"<<endl;
        }
        else
        {
            for(int i=0;i<=top;i++)
            {

                cout<<arr[i]<<endl;
            }
        }
    }

    void menu()
    {
        cout<<"Enter the 1 for push"<<endl;
        cout<<"Enter the 2 for pop"<<endl;
        cout<<"Enter the 3 for peek"<<endl;
        cout<<"Enter the 4 for display"<<endl;
        cout<<"Enter the 5 for exit"<<endl;
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
            cout<<"Enter the value for push"<<endl;
            cin>>val;
            st.push(val);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.topp();
            break;
        case 4:
            st.display();
            break;
        case 5:
            break;
        default:
            cout<<"Please enter the right choice"<<endl;

        }
    }


    return 0;
}
