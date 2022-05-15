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
};

int main()
{
    stackk st;

     st.push(16);
      st.push(11);
       st.push(55);
   st.display();
    return 0;
}
