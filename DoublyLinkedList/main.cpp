#include <iostream>

using namespace std;
class node {

  public:
    int data;
    node* next;
    node* pre;
    node(int val){

        data=val;
        next=NULL;
        pre=NULL;
        }
};
void insertAtdbeg(node* &head,node* &tail, int val)
{
   node* n= new node(val);
   if(head==NULL)
   {
      n->next=NULL;
      head=tail=n;
   }else
   {
       n->next=head;
       head->pre=n;
       head=n;
       cout<<"Insertion successfully"<<endl;
   }
}
void insertAtdend(node* &head,node* &tail,int val)
{
    node* n =new  node(val);
    if(head==NULL)
    {
        n->pre=NULL;
        head=tail=n;
    }
    else
    {
        n->pre=tail;
        tail->next=n;
        tail=n;
        cout<<"Insertion successfully"<<endl;
    }
}
void insertafter(node* head, node* tail,int val,int after)
{

    node* temp=head;
    if(head==NULL)
    {
        cout<<"Operation is not possible"<<endl;
    }
    else
    {
          while((temp!=NULL)&&temp->data!=after)
          {
              temp=temp->next;
          }
          if(temp==NULL)
          {
              cout<<"Operation is not possible"<<endl;
              cout<<after<<"The element is present"<<endl;
          }
          else
          {
              if(temp->next==NULL)
              {
                  insertAtdend(head,tail,val);

              }
              else
              {
                 node* n =new node(val);
                 n->next=temp->next;
                 n->pre=temp;
                 temp->next->pre=n;
                 temp->next=n;
              }
          }
    }
}
void insertBefore(node* &head,node* &tail,int val, int bf)
{
    node* temp=head;
    if(head==NULL)
    {
        cout<<"Operation is not possible"<<endl;
    }
    else
    {
          while((temp!=NULL)&&temp->data!=bf)
          {
              temp=temp->next;
          }
          if(temp==NULL)
          {
              cout<<"Operation is not possible"<<endl;
              cout<<bf<<"The element is present"<<endl;
          }
          else
          {
              if(temp->pre==NULL)
              {
                  insertAtdbeg(head,tail,val);

              }
              else
              {
                 node* n =new node(val);

                 n->pre=temp->pre;
                 n->next=temp;
                 temp->pre->next=n;
                 temp->pre=n;
              }
          }
    }
}
void deletebeg(node* &head)
{
    node* temp=head;
    temp->next->pre=NULL;
    head=temp->next;

}
void deleteEnd(node* &tail)
{
    node* temp=tail;
    temp->pre->next=NULL;
    tail=temp->pre;
}
void deleteAnode(node* &head,node* &tail,int del)
{
    node* temp=head;
    if(head==NULL)
    {
        cout<<"Operation is not possible"<<endl;
    }
    else
    {
          while((temp!=NULL)&&temp->data!=del)
          {
              temp=temp->next;
          }
          if(temp==NULL)
          {
              cout<<"Operation is not possible"<<endl;
              cout<<del<<"The element is present"<<endl;
          }
          else
          {
              if(temp->pre==NULL)
              {
                  deletebeg(head);

              }
              else if(temp->next==NULL)
              {
                  deleteEnd(tail);
              }
              else
              {

               temp->pre->next=temp->next;
               temp->next->pre=temp->pre;


              }
          }
    }
}

void Displayforward(node* &head)
{
   node* temp =head;
    if(head==NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

void DisplayBackword(node* &tail)
{
    node * temp =tail;
    if(tail==NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->pre;
        }
        cout<<endl;
    }
}

void menu()
{
    cout<<"Enter 1 for insert at beg"<<endl;
    cout<<"Enter 2 for forward display"<<endl;
    cout<<"Enter 3 for Backward display"<<endl;
    cout<<"Enter 4 for insert at end "<<endl;
    cout<<"Enter 5 for insert after a element"<<endl;
    cout<<"Enter 6 for Insert before a element"<<endl;
    cout<<"Enter 7 for delete from beg "<<endl;
    cout<<"Enter 8 for delete from end "<<endl;
    cout<<"Enter 9 for delete a node "<<endl;
}
int main()
{
   int val,choise,after,bf,del;
   node* head=NULL;
   node* tail=NULL;
   while(1)
   {
       menu();
       cin>>choise;
       switch(choise)
       {
      case 1:
        cout<<"Enter a value to  insert at beg"<<endl;
        cin>>val;
        insertAtdbeg(head,tail,val);
        break;
      case 2:
        Displayforward(head);
        break;
      case 3:
        DisplayBackword(tail);
        break;
      case 4:
        cout<<"Enter a value to  insert at beg"<<endl;
        cin>>val;
        insertAtdend(head,tail,val);
        break;
      case 5:
          cout<<"Enter a value for insert after a value"<<endl;
          cin>>val;
          cout<<"Enter a value which after you want to insert"<<endl;
          cin>>after;
          insertafter(head,tail,val,after);
          break;
      case 6:
          cout<<"Enter a value for insert before a value"<<endl;
          cin>>val;
          cout<<"Enter a value which before you want to insert"<<endl;
          cin>>bf;
          insertBefore(head,tail,val,bf);
          break;
      case 7:
        deletebeg(head);
        break;
      case 8:
        deleteEnd(tail);
        break;
      case 9:
        cout<<"Enter the  value for delete"<<endl;
        cin>>del;
        deleteAnode(head,tail,del);
        break;
      default:
        cout<<"Please enter the  right choise"<<endl;
        }
   }

    return 0;
}
