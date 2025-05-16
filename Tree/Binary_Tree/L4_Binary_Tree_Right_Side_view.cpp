#include<iostream>
#include<bits/stdc++.h>

using namespace std;


struct node{
  int data;
  struct node* right;
  struct node* left;
  node(int val){
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

void array2bt(vector<int> &vec,node* root, int i,int n){
  if(2*i+1<n){
    node* l = new node(vec[2*i+1]);
    root->left=l;
    array2bt(vec,root->left,2*i+1,n);
  }
  if(2*i+2<n){
    node* r = new node(vec[2*i+2]);
    root->right= r;
    array2bt(vec,root->right,2*i+2,n);
  }
}

vector<int> rightsideBFS(node* root){
  queue<node*>que;
  que.push(root);
  vector<int> right;
  while(!que.empty()){
    int n= que.size();
    int end;
    while(n--){
      node* f = que.front();
      que.pop();
      end=f->data;
      if(f->left){
        que.push(f->left);
      }
      if(f->right){
        que.push(f->right);
      }
    }
    right.push_back(end);
  }
  return right; 
}



int main(){
  vector<int> vec={1,2,3,4,5,6,7,8,9,10};
  node* root = new node(vec[0]);
  array2bt(vec,root,0,vec.size());

  //right side view using bfs;
  vector<int> ans = rightsideBFS(root);
  for(int num:ans){
    cout<<num<<" ";
  }
  //right side veiw using dfs;
  // vector<int> dfs = rightsidedfs(root);
}