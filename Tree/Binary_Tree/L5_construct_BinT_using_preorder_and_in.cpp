#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct node{
  int data;
  struct node* left;
  struct node* right;

  node(int val){
    data=val;
    left=nullptr;
    right=nullptr;
  }
};


node* solve(vector<int>& preorder,vector<int>&inorder,int start,int end ,int& idx){
  if(start>end) return nullptr;

  int rootval =preorder[idx];
  int i=start;
  for(;i<end;i++){
    if(rootval==inorder[i]){
      break;
    }
  }
  node* root=new node(rootval);
  idx++;
  root->left=solve(preorder,inorder,start,i-1,idx);
  root->right=solve(preorder,inorder,i+1,end,idx);
  return root;
}


node* buildTree(vector<int>&preorder,vector<int>&inorder){
  int n=preorder.size();
  int idx = 0;
  return solve(preorder,inorder,0,n-1,idx);
}


void levelorder(node* root){
  queue<node*> que;
  que.push(root);

  while(!que.empty()){
    int n = que.size();
    while(n--){
      node* f = que.front();
      que.pop();
      cout<<f->data<<" ";
      if(f->left) que.push(f->left);
      if(f->right) que.push(f->right);
    }
    
  }
  return;
}
int main(){
  vector<int>preorder = {3,9,20,15,7};
  vector<int>inorder = {9,3,15,20,7};
  node* root=buildTree(preorder,inorder);

  // print the level order traversal
  levelorder(root);

}