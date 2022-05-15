#include <iostream>

using namespace std;
class node{
 public:
     int data;
     node *next;
      node(int val){
        data =val;
        next=NULL;
      }
};

void insertAtBeg(node* &head,int val)
{
    node* n= new node(val);

    if(head==NULL)
    {
        head=n;
        n->next=head;
        return;
    }
    else
    {
         node* temp=head;
           while(temp->next!=head)
         {
            temp=temp->next;
         }
         temp->next=n;
         n->next=head;
         head=n;
    }
}
void insertAtend(node* &head,int val)
{
    node* n= new node(val);

    if(head==NULL)
    {
        head=n;
        n->next=head;
        return;
    }
    else
    {
         node* temp=head;
           while(temp->next!=head)
         {
            temp=temp->next;
         }
         temp->next=n;
         n->next=head;

    }
}
void insertAfter (node *head ,int val ,int after)
{
    node *n = new node(val);
    node *temp;
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    else
    {

        temp =head;
        while(temp->data!=after&&temp->next!=head)
        {
            temp=temp->next;
        }
         if(temp->next==head)
         {
             cout<<"this operation is not possible "<<endl;
         }
         else
         {
             n->next=temp->next;
            temp->next=n;
         }

       }

    }

void insertBefore (node *head, int val ,int before)
{
    node *n =new node(val);
    if(head==NULL)
    {
        cout<<"The list is empty "<<endl;
    }
    else
    {
        node *temp;
        node *current=head;
        while(current->data!=before&&current->next!=head)
        {
            temp=current;
            current=current->next;
        }
        if(current->next==head)
        {
            cout<<"This operation is not possible because this is not exit in this list"<<endl;
        }
        else
        {
            n->next=temp->next;
            temp->next=n;
        }


    }

}
void deleteAthead(node * head)
{
    node *temp;

    while(temp->next!=head)
    {
        temp=temp->next;
    }
    node* todelete = head;
    temp->next=head->next;
    head=head->next;

    delete todelete;
}

void delpos(node *head, int pos)
{
     if(pos==1)
     {
         deleteAthead(head);
         return;
     }
     node *temp=head;
     int countt=1;
     node *current;
     while(countt!=pos-1)
     {
         temp=temp->next;
         countt++;
     }
     node *todelete =temp->next;
     temp->next=temp->next->next;
     delete todelete;

}



void displaylist(node* head)
{

    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    else
    {
         node* temp=head;
         do
         {
            cout<<temp->data<<" ";
            temp=temp->next;
         }while(temp!=head);
         cout<<endl;
    }

}
void menu()
{
    cout<<"Enter the 1 for insert at beg"<<endl;
    cout<<"Enter the 2 for display"<<endl;
    cout<<"Enter the 3 for insert at end"<<endl;
    cout<<"Enter the 4 for insert at after a value"<<endl;
    cout<<"Enter the 5 for insert at before a value"<<endl;
    cout<<"Enter the 6 for delete at possition"<<endl;
    cout<<"Enter the 7 for delete at end"<<endl;
}
int main()
{
   int choice,val,after,before,pos;
   node* head=NULL;

   while(1)
   {
       menu();
       cin>>choice;
       switch(choice)
       {
       case 1:
        cout<<"Enter the value for insert "<<endl;
        cin>>val;
        insertAtBeg(head,val);
        break;
       case 2:
        displaylist(head);
        break;

       case 3:
        cout<<"Enter the value for insert "<<endl;
        cin>>val;
          insertAtend(head,val);
          break;
       case 4:
        cout<<"Enter the value for insert after a  value"<<endl;
        cin>>val;
        cout<<"Enter the a after value "<<endl;
        cin>>after;
        insertAfter(head,val,after);
        break;
       case 5:
        cout<<"Enter value for insert before a value"<<endl;
        cin>>val;
        cout<<"Enter the a before value"<<endl;
        cin>>before;
        insertBefore(head,val,before);
        break;
       case 6:
           cout<<"Enter possition for delete element"<<endl;
           cin>>pos;
        delpos(head,pos);
        break;
       case 7:
        deleteAthead(head);
        break;
        default:
        cout<<"Please enter right choice"<<endl;
       }
   }
    return 0;
}
