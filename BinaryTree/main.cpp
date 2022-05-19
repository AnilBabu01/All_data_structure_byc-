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

};
int main()
{

   Traversals Preorder;
   node *p = new node(4);
   node *p1 = new node(1);
   node *p2 = new node(6);
   node *p3 = new node(5);
   node *p4 = new node(2);


   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;

  Preorder.PreOrder(p);

    return 0;
}
