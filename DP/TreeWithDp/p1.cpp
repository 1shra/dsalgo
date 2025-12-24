// The first problem we solve is as follows: Given a tree T of N nodes, where each node i has Ci coins attached with it. You have to choose a subset of nodes such that no two adjacent nodes(i.e. nodes connected directly by an edge) are chosen and sum of coins attached with nodes in chosen subset is maximum.

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
  public:
  int data;
  TreeNode* left;
  TreeNode* right;
    TreeNode(int data1){
      this->data=data1;
      this->left=nullptr;
      this->right=nullptr;
    }
};
void creating_tree(TreeNode* head,int i,vector<int> &vec){
  if(i==vec.size()){
    return;
  }
  if((2*i)+1<vec.size()){
    TreeNode* l = new TreeNode(vec[(2*i)+1]);
    head->left = l;
    creating_tree(head->left,(2*i)+1,vec);
  }
  if((2*i)+2<vec.size()){
    TreeNode* r = new TreeNode(vec[(2*i)+2]);
    head->right=r;
    creating_tree(head->right,(2*i)+2,vec);
  }
}
void levelOrderTraversal(TreeNode* root){
  queue<TreeNode*> que;
  que.push(root);
  while(!que.empty()){
    int n=que.size();
    while(n--){
      TreeNode* t =que.front();
      que.pop();
      cout<<t->data<<" ";
      if(t->left){
        que.push(t->left);
      }
      if(t->right){
        que.push(t->right);
      }
    }
    cout<<endl;
  }
}
pair<int,int> dfs(TreeNode* root){
  if(!root) return {0,0};
  auto left = dfs(root->left);
  auto right = dfs(root->right);
  
  int rob = root->data+left.first+right.first;
  int notRob = left.second+right.second;
  return {notRob,rob};
}

int main(){
  vector<int> vec = {4,5,6,7,8,5,9,10,11,12,13,14,15,16,17,18,19,20};
  TreeNode* head = new TreeNode(vec[0]);
  creating_tree(head,0,vec);
  levelOrderTraversal(head);
  auto res = dfs(head);
  cout<<max(res.first,res.second)<<endl;
}
