#include<iostream>
using namespace std;


//! Declaration
struct Node{
  int data;
  struct Node* left;
  struct Node* right;

  Node(int val){
    data=val;
    left=nullptr;
    right=nullptr;
  }
};


//!Inorder Traversal
void inorder_Traversal(Node* root){
  if(root==nullptr){
    return;
  }
  inorder_Traversal(root->left);
  cout<<root->data<<" ";
  inorder_Traversal(root->right); 
  return;
}

//!Preorder Traversal
void preorder_Traversal(Node* root){
  if(root==nullptr){
    return;
  }
  cout<<root->data<<" ";
  preorder_Traversal(root->left);
  preorder_Traversal(root->right);

}



//!Postorder Traversal
void postorder_Traversal(Node* root){
  if(root==nullptr){
    return;
  }
  postorder_Traversal(root->left);
  postorder_Traversal(root->right);
  cout<<root->data<<" ";
}
int main(){
  struct Node* root=new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->right->left = new Node(5);
  cout<<"Inorder Traversal: ";
  inorder_Traversal(root);
  cout<<endl;

  cout<<"Preorder Traversal: ";
  preorder_Traversal(root);
  cout<<endl;
  cout<<"Postorder Traversal: ";
  postorder_Traversal(root);
  cout<<endl;
}