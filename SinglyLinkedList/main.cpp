#include <iostream>

using namespace std;

class node {

  public:
    int data;
    node* next;
    node(int val){

        data=val;
        next=NULL;
        }
};
void insertAttail(node* &head, int val)
{
    node* n = new node(val);

    if(head==NULL)
      {
        head=n;
        return;
      }

        node* temp = head;
        while(temp->next!=NULL)
        {
        temp=temp->next;
        }
         temp->next=n;
}

void insertAthead(node* &head ,int val)
{
    node* n = new node(val);
    n->next=head;
    head=n;
}

void insertAfter(node* &head ,int val, int after )
{
    int c=0;
    node* n = new node(val);
    node* temp =head;
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }

       while(temp!=NULL)
       {
           if(temp->data==after)
           {
                 ++c;
                 n->next=temp->next;
                 temp->next=n;

               return;
           }
           temp=temp->next;
       }
    if(c==0)
     {
         cout<<"Insert value at end "<<endl;
         insertAttail(head,val);
     }
}

void insertBefore(node* &head, int val,int bf )
{

    int c=0;
    node* n = new node(val);
    node* prev;

    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    else
    {
         node* curr =head;
         while(curr->data!=bf&& curr!=NULL)
         {
             prev=curr;
           curr=curr->next;
         }
         if(curr==NULL )
            {
              cout<<"The list is ended so this element is not present"<<endl;

            }
            else
            {
                n->next=curr;
                prev->next=n;

            }

    }
}
void delebeg(node* &head)
{

    node* temp=head;
    if(head==NULL)
    {
        cout<<"The is empty"<<endl;
    }
    head=temp->next;
}

void deleEnd(node* &head)
{
    if(head== NULL)
    {
        cout<<"The linked list is empty "<<endl;
    }
    else
    {
         int s;
        node* temp=head;
        while(temp->next->next!=NULL)
        {

            temp=temp->next;
        }

        temp->next=NULL;

}
}
void deleteAfter(node* &head,int delAfter)
{
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;

    }
    else
    {
        node* temp=head;
        while(temp!=NULL&&temp->data!=delAfter)
        {
            temp=temp->next;
        }
         if(temp==NULL)
         {
             cout<<"The operation is not possible because this element is not present"<<endl;
         }
         else
         {

           temp->next=temp->next->next;
         }
    }
}

void deleteBefore(node* &head ,int delbefore)
{
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    else
    {
        node* curr=head;
        node * prev;
        node * temp;
        while(curr!=NULL&&curr->data!=delbefore)
        {
            temp=prev;
            prev=curr;
            curr=curr->next;
        }
        if(curr==NULL)
        {
            cout<<"The operation is not possible because this element is not present"<<endl;
        }
        else
        {
            temp->next=prev->next;
        }

    }
}
void deleteAelement(node* &head,int delkey)
{
    if(head==NULL)
    {
        cout<<"The list is empty "<<endl;
    }
    else
    {
        node* curr=head;
        node* prev;
        while(curr!=NULL&&curr->data!=delkey)
        {
            prev=curr;
            curr=curr->next;
        }
        if(curr==NULL)
        {
            cout<<"The operation is not possible because this element is present "<<endl;
        }
       else
        {
            prev->next=curr->next;
        }

    }
}
void reverseLinkedlist(node* &head)
{
    node* preptr =NULL;
    node* curptr= head;
    node* nextptr;
      while(curptr!=NULL)
      {
          nextptr=curptr->next;
          curptr->next=preptr;

          preptr=curptr;
          curptr=nextptr;
      }
      head=preptr;

}
void SearchItem(node* &head,int key)
{
    if(head==NULL)
    {
        cout<<"linked list is empty"<<endl;

    }
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            cout<<"yes this value is present in this list"<<key<<endl;
            temp=temp->next;
        }
    }


}
void Menu()
{
    cout<<"enter 1 for insert at end "<<endl;
    cout<<"enter 2  for insert at beg "<<endl;
    cout<<"enter 3 for display "<<endl;
    cout<<"Enter 4 for search value"<<endl;
    cout<<"Enter 5 for insert after a value"<<endl;
    cout<<"Enter 6 for insert before a value"<<endl;
    cout<<"Enter 7 for delete at beg "<<endl;
    cout<<"Enter 8 for delete at end "<<endl;
    cout<<"Enter 9 for reverse list "<<endl;
    cout<<"Enter 10 for delete after a element"<<endl;
    cout<<"Enter 11 for delete before a element"<<endl;
    cout<<"Enter 12 for delete a element "<<endl;
}


void display (node* head)
{
    int d;
    node* temp=head;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }

    while(temp!=NULL)
    {

        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    int choise,val,af,bf,delAfter,delbefore,del;
    node* head=NULL;
      while(1)
      {
          Menu();
          cin>>choise;
          switch(choise)
          {
          case 1:
            cout<<"enter the value insert at end "<<endl;
            cin>>val;
            insertAttail(head,val);
            break;
          case 2:
            cout<<"enter the value to insert at beg"<<endl;
            cin>>val;
            insertAthead(head,val);
            break;
          case 3:
            display(head);
            break;
          case 4:
            cout<<"Enter value for search "<<endl;
            cin>>val;
            SearchItem(head,val);
            break;
          case 5:
            cout<<"Enter the value for insert after a value"<<endl;
            cin>>val;
            cout<<"enter the value which after you want insert a value"<<endl;
            cin>>af;
            insertAfter(head,val,af);
            break;
          case 6:
            cout<<"Enter the value for insert before a value"<<endl;
            cin>>val;
            cout<<"Enter the value which before you want to insert value"<<endl;
            cin>>bf;
            insertBefore(head,val,bf);
            break;
          case 7:
            delebeg(head);
            break;
          case 8:
            deleEnd(head);
            break;
          case 9:
            reverseLinkedlist(head);
            break;
          case 10:
            cout<<"Enter the value which after you want to delete"<<endl;
            cin>>delAfter;
            deleteAfter(head,delAfter);
            break;
          case 11:
            cout<<"Enter the value which before you want to delete"<<endl;
            cin>>delbefore;
            deleteBefore(head,delbefore);
            break;
          case 12:
            cout<<"Enter the value for delete "<<endl;
            cin>>del;
            deleteAelement(head,del);
             break;
            default :
            cout<<"please enter the right choise"<<endl;
          }
      }

   return 0;
}
