#include <iostream>

using namespace std;
class node{
   public:
   int data;
   node *left;
   node *right;

     node(int val)
     {
         data=val;
         left=NULL;
         right=NULL;
     }


};
class Traversals{

  public:
      void PreOrder(node* root){
       if(root!=NULL)
       {
           cout<<root->data<<" ";
           PreOrder(root->left);
           PreOrder(root->right);
       }

     }
      void PostOrder(node* root){
       if(root!=NULL)
       {
           PostOrder(root->left);
           PostOrder(root->right);
           cout<<root->data<<" ";

       }
    }
      void InOrder(node* root){
       if(root!=NULL)
       {

           InOrder(root->left);
           cout<<root->data<<" ";
           InOrder(root->right);
       }

     }

};
int main()
{

   Traversals traversals;
   node *p = new node(4);
   node *p1 = new node(1);
   node *p2 = new node(6);
   node *p3 = new node(5);
   node *p4 = new node(2);


   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;
  cout<<"PreOder traversal "<<endl;
  traversals.PreOrder(p);
  cout<<endl;
  cout<<"PostOder traversal "<<endl;
  traversals.PostOrder(p);
  cout<<endl;
  cout<<"InOder traversal "<<endl;
  traversals.InOrder(p);

    return 0;
}
